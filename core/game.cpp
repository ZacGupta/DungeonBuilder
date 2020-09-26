#include "game.h"
#include <core/dungeon/roomedge.h>
#include <iostream>

namespace core {

Game* Game::theInstance{nullptr};

Game::Game() : _builder{nullptr}, _level{nullptr} {
}

Game::~Game() {
    theInstance = nullptr;
}

Game* Game::instance() {
    if (not theInstance) {
        theInstance = new Game;
        return theInstance;
    }
    return nullptr;
}

void Game::setDungeonType(std::unique_ptr<dungeon::DungeonLevelBuilder> builder) {
    if (_level) {
        delete _level;
        _level = nullptr;
    }
    _builder = std::move(builder);
}

void Game::createExampleLevel() {

    std::vector <std::shared_ptr<dungeon::Room>> rooms{std::vector <std::shared_ptr<dungeon::Room>>()};
    rooms.reserve(9);

    _builder->buildDungeonLevel("Example Level", 3, 3);

    //Build 9 rooms
    rooms.push_back(_builder->buildRoom(1));
    rooms.push_back(_builder->buildRoom(2));
    rooms.push_back(_builder->buildRoom(3));
    rooms.push_back(_builder->buildRoom(4));
    rooms.push_back(_builder->buildRoom(5));
    rooms.push_back(_builder->buildRoom(6));
    rooms.push_back(_builder->buildRoom(7));
    rooms.push_back(_builder->buildRoom(8));
    rooms.push_back(_builder->buildRoom(9));

    //Build the doorways from room 1-9, always building east first (unless in the last column), then south (unless in the last row)
    _builder->buildDoorWay(rooms.at(0), rooms.at(1), dungeon::Direction::East, dungeon::MoveConstraints::None);
    _builder->buildDoorWay(rooms.at(0), rooms.at(3), dungeon::Direction::South, dungeon::MoveConstraints::DestinationImpassable);
    _builder->buildDoorWay(rooms.at(1), rooms.at(2), dungeon::Direction::East, dungeon::MoveConstraints::OriginImpassable | dungeon::MoveConstraints::DestinationImpassable);
    _builder->buildDoorWay(rooms.at(1), rooms.at(4), dungeon::Direction::South, dungeon::MoveConstraints::None);
    _builder->buildDoorWay(rooms.at(2), rooms.at(5), dungeon::Direction::South, dungeon::MoveConstraints::DestinationLocked);
    _builder->buildDoorWay(rooms.at(3), rooms.at(4), dungeon::Direction::East, dungeon::MoveConstraints::DestinationImpassable);
    _builder->buildDoorWay(rooms.at(3), rooms.at(6), dungeon::Direction::South, dungeon::MoveConstraints::OriginImpassable | dungeon::MoveConstraints::DestinationImpassable);
    _builder->buildDoorWay(rooms.at(4), rooms.at(5), dungeon::Direction::East, dungeon::MoveConstraints::None);
    _builder->buildDoorWay(rooms.at(4), rooms.at(7), dungeon::Direction::South, dungeon::MoveConstraints::None);
    _builder->buildDoorWay(rooms.at(6), rooms.at(7), dungeon::Direction::East, dungeon::MoveConstraints::OriginLocked | dungeon::MoveConstraints::DestinationLocked);
    _builder->buildDoorWay(rooms.at(7), rooms.at(8), dungeon::Direction::East, dungeon::MoveConstraints::None);

    //Build Entrance and Exit
    _builder->buildEntrance(rooms.at(0), dungeon::Direction::North);
    _builder->buildExit(rooms.at(8), dungeon::Direction::East);

    //Items and creatures
    _builder->buildCreature(rooms.at(2));
    _builder->buildCreature(rooms.at(4));
    _builder->buildCreature(rooms.at(8));

    _builder->buildItem(rooms.at(2));
    _builder->buildItem(rooms.at(4));
    _builder->buildItem(rooms.at(6));

    _level = _builder->getDungeonLevel();
}

void Game::createRandomLevel(const std::string& name, const int width, const int height) {
    if (not _builder or width < 1 or  width > 4 or height < 1 or height > 4) {
        return;
    }

    //If we have one of each move constraint, it naturally results in a 33.33% probability for each type of doorway,
    //so by simply adding 'None' twice, we can increase the probability of traversable doorways to 40%,
    //and reduce the probability of the impassable and locked doorways to 30% each.
    std::vector<dungeon::MoveConstraints> constraints{
        dungeon::MoveConstraints::None,
        dungeon::MoveConstraints::None,
        dungeon::MoveConstraints::OriginImpassable,
        dungeon::MoveConstraints::DestinationImpassable,
        dungeon::MoveConstraints::OriginImpassable | dungeon::MoveConstraints::DestinationImpassable,
        dungeon::MoveConstraints::OriginLocked,
        dungeon::MoveConstraints::OriginLocked | dungeon::MoveConstraints::DestinationImpassable,
        dungeon::MoveConstraints::DestinationLocked,
        dungeon::MoveConstraints::OriginImpassable | dungeon::MoveConstraints::DestinationLocked,
        dungeon::MoveConstraints::OriginLocked | dungeon::MoveConstraints::DestinationLocked};

    std::vector <std::shared_ptr<dungeon::Room>> rooms{std::vector <std::shared_ptr<dungeon::Room>>()};
    int numOfRooms{width * height};
    rooms.reserve(numOfRooms);
    _builder->buildDungeonLevel(name, width, height);

    //Build rooms
    for (int i{0}; i < numOfRooms; ++i) {
        rooms.push_back(_builder->buildRoom(i + 1));
    }

    //Build doorways, always building east first (unless in the last column or the only room), then south (unless in the last or only row)
    //Generally speaking, East will always be built, and the decision to build South will be random.
    for (int i{0}; i < numOfRooms; ++i) {
        int roomID{i + 1};
        int adjacentEast{i + 1};
        int adjacentSouth{i + width};

        if (roomID != numOfRooms) {
            //Last Column
            if (roomID % width == 0) {
                if (width == 1) {
                    _builder->buildDoorWay(rooms.at(i), rooms.at(adjacentSouth), dungeon::Direction::South, constraints.at((randomInt(10))));
                }
                else {
                    if (randomDouble() < 0.69) {
                        _builder->buildDoorWay(rooms.at(i), rooms.at(adjacentSouth), dungeon::Direction::South, constraints.at((randomInt(10))));
                    }
                }
            }
            //Last row
            else if (roomID > (width * height) - width) {
                _builder->buildDoorWay(rooms.at(i), rooms.at(adjacentEast), dungeon::Direction::East, constraints.at((randomInt(10))));
            }
            //All other rooms
            else {
                _builder->buildDoorWay(rooms.at(i), rooms.at(adjacentEast), dungeon::Direction::East, constraints.at((randomInt(10))));
                if (height != 1) {
                    if (randomDouble() < 0.69) {
                        _builder->buildDoorWay(rooms.at(i), rooms.at(adjacentSouth), dungeon::Direction::South, constraints.at((randomInt(10))));
                    }
                }
            }
        }
    }
    //Build Entrance
    int rng{randomInt(width)};
    int entranceRoom{rng};

    //Room 1
    if (rng == 0 or width == 1) {
        double randomDirection{randomDouble()};
        if (width == 1) {
            if (randomDirection < 0.33) {
                _builder->buildEntrance(rooms.at(entranceRoom), dungeon::Direction::North);
            } else if (randomDirection > 0.33 and randomDirection < 0.66) {
                _builder->buildEntrance(rooms.at(entranceRoom), dungeon::Direction::West);
            } else {
                _builder->buildEntrance(rooms.at(entranceRoom), dungeon::Direction::East);
            }
        } else {
            if (randomDirection < 0.50) {
                _builder->buildEntrance(rooms.at(entranceRoom), dungeon::Direction::North);
            } else {
                _builder->buildEntrance(rooms.at(entranceRoom), dungeon::Direction::West);
            }
        }
    }
    //Room 2
    else if (rng == 1 or width == 2) {
        if (width != 2) {
            _builder->buildEntrance(rooms.at(entranceRoom), dungeon::Direction::North);
        } else {
            if (randomDouble() < 0.50) {
                _builder->buildEntrance(rooms.at(entranceRoom), dungeon::Direction::North);
            } else {
                _builder->buildEntrance(rooms.at(entranceRoom), dungeon::Direction::East);
            }
        }
    }
    //Room 3
    else if (rng == 2 or width == 3) {
        if (width != 3) {
            _builder->buildEntrance(rooms.at(entranceRoom), dungeon::Direction::North);
        } else {
            if (randomDouble() < 0.50) {
                _builder->buildEntrance(rooms.at(entranceRoom), dungeon::Direction::North);
            } else {
                _builder->buildEntrance(rooms.at(entranceRoom), dungeon::Direction::East);
            }
        }
    }
    //Room 4
    else if (rng == 3 or width == 4) {
        if (randomDouble() < 0.50) {
            _builder->buildEntrance(rooms.at(entranceRoom), dungeon::Direction::North);
        } else {
            _builder->buildEntrance(rooms.at(entranceRoom), dungeon::Direction::East);
        }
    }

    //Build Exit
    rng = randomInt(width);
    int exitRoom{((width * height) - width) + rng};

    //Room 1
    if (rng == 0 or width == 1) {
        if (width == 1) {
            if (height == 1) {
                _builder->buildExit(rooms.at(exitRoom), dungeon::Direction::South);
            } else {
                double randomDirection{randomDouble()};
                if (randomDirection < 0.33) {
                    _builder->buildExit(rooms.at(exitRoom), dungeon::Direction::South);
                } else if (randomDirection > 0.33 and randomDirection < 0.66) {
                    _builder->buildExit(rooms.at(exitRoom), dungeon::Direction::East);
                } else {
                    _builder->buildExit(rooms.at(exitRoom), dungeon::Direction::West);
                }
            }
        } else {
            if (height == 1) {
                _builder->buildExit(rooms.at(exitRoom), dungeon::Direction::South);
            } else {
                if (randomDouble() < 0.50) {
                    _builder->buildExit(rooms.at(exitRoom), dungeon::Direction::South);
                } else {
                    _builder->buildExit(rooms.at(exitRoom), dungeon::Direction::West);
                }
            }

        }
    }
    //Room 2
    else if (rng == 1 or width == 2) {
        if (width != 2 or height == 1) {
            _builder->buildExit(rooms.at(exitRoom), dungeon::Direction::South);
        } else {
            if (randomDouble() < 0.50) {
                _builder->buildExit(rooms.at(exitRoom), dungeon::Direction::South);
            } else {
                _builder->buildExit(rooms.at(exitRoom), dungeon::Direction::East);
            }
        }
    }
    //Room 3
    else if (rng == 2 or width == 3) {
        if (width != 3 or height == 1) {
            _builder->buildExit(rooms.at(exitRoom), dungeon::Direction::South);
        } else {
            if (randomDouble() < 0.50) {
                _builder->buildExit(rooms.at(exitRoom), dungeon::Direction::South);
            } else {
                _builder->buildExit(rooms.at(exitRoom), dungeon::Direction::East);
            }
        }
    }
    //Room 4
    else if (rng == 3 or width == 4) {
        if (height == 1) {
            _builder->buildExit(rooms.at(exitRoom), dungeon::Direction::South);
        } else {
            if (randomDouble() < 0.50) {
                _builder->buildExit(rooms.at(exitRoom), dungeon::Direction::South);
            } else {
                _builder->buildExit(rooms.at(exitRoom), dungeon::Direction::East);
            }
        }
    }
    //Add items and creatures
    for (int i = 0; i < numOfRooms; ++i) {
        if (i != entranceRoom) {
            if (randomDouble() < 0.25) {
                _builder->buildCreature(rooms.at(i));
            }
            if (randomDouble() < 0.35) {
                _builder->buildItem(rooms.at(i));
            }
        }
        if (i == exitRoom) {
            _builder->buildCreature(rooms.at(i));
            _builder->buildItem(rooms.at(i));
        }
    }
    _level = _builder->getDungeonLevel();
}

const std::ostream& Game::displayLevel(std::ostream& out) const {
    if (_level) {
        out << "\n" << _level->name() << std::endl;
        std::vector<std::string> dungeon {_level->display()};
        for (std::string row : dungeon) {
            out << row << std::endl;
        }
        return out;
    }
    return out << "\nThere is no level to display!\n" << std::endl;
}

const std::ostream& Game::describeDungeon(std::ostream& out) const {
    if (_level) {
        return out << "\n" << _level->description() << "\n" << std::endl;
    }
    return out << "\nThere is no level to describe!\n" << std::endl;;
}

const std::ostream& Game::describeRoom(const int id, std::ostream& out) const {
    if (_level and _level->retrieveRoom(id)) {
        return out << _level->retrieveRoom(id)->description() << "\n" << std::endl;;
    }
    return out << "This room doesn't exist!\n Please choose between 1-" << std::to_string(_level->numberOfRooms()) + ".\n" << std::endl;
}


double Game::randomDouble() {
    return _realDistribution(_randomGenerator);
}
int Game::randomInt(int possibilities) const {
    //This just returns a random integer between 0 to number of possibilities (exclusive),
    //It's mainly used to simplify the selection of random doorways.
    static std::mt19937 randomGenerator{uint32_t(time(nullptr))};
    static std::uniform_int_distribution<int> distribution{0, RAND_MAX};
    return (distribution(randomGenerator) % possibilities);
}
}
