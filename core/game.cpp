#include "game.h"
#include <core/dungeon/roomedge.h>

namespace core {

Game* Game::theInstance{nullptr};

Game::Game() : _builder{nullptr}, _level{nullptr} {
    std::cout << "Created Game" << std::endl;
}

Game::~Game() {
    theInstance = nullptr;
    std::cout << "Destroyed Game" << std::endl;
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
    }
    _builder = std::move(builder);
}

void Game::createExampleLevel() {
    if (_level) {
        delete _level;
        _level = nullptr;
    }

    std::vector <std::shared_ptr<dungeon::Room>> rooms{std::vector <std::shared_ptr<dungeon::Room>>()};
    rooms.reserve(9);

    _builder->BuildDungeonLevel("Example Level", 3, 3);

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
    //Room 1
    _builder->buildDoorWay(rooms.at(0), rooms.at(1), dungeon::Direction::East, dungeon::MoveConstraints::None);
    _builder->buildDoorWay(rooms.at(0), rooms.at(3), dungeon::Direction::South, dungeon::MoveConstraints::DestinationImpassable);
    //Room 2
    _builder->buildDoorWay(rooms.at(1), rooms.at(2), dungeon::Direction::East, dungeon::MoveConstraints::OriginImpassable | dungeon::MoveConstraints::DestinationImpassable);
    _builder->buildDoorWay(rooms.at(1), rooms.at(4), dungeon::Direction::South, dungeon::MoveConstraints::None);
    //Room 3
    _builder->buildDoorWay(rooms.at(2), rooms.at(5), dungeon::Direction::South, dungeon::MoveConstraints::DestinationLocked);
    //Room 4
    _builder->buildDoorWay(rooms.at(3), rooms.at(4), dungeon::Direction::East, dungeon::MoveConstraints::DestinationImpassable);
    _builder->buildDoorWay(rooms.at(3), rooms.at(6), dungeon::Direction::South, dungeon::MoveConstraints::OriginImpassable | dungeon::MoveConstraints::DestinationImpassable);
    //Room 5
    _builder->buildDoorWay(rooms.at(4), rooms.at(5), dungeon::Direction::East, dungeon::MoveConstraints::None);
    _builder->buildDoorWay(rooms.at(4), rooms.at(7), dungeon::Direction::South, dungeon::MoveConstraints::None);
    //Room 6 - None
    //Room 7
    _builder->buildDoorWay(rooms.at(6), rooms.at(7), dungeon::Direction::East, dungeon::MoveConstraints::OriginLocked | dungeon::MoveConstraints::DestinationLocked);
    //Room 8
    _builder->buildDoorWay(rooms.at(7), rooms.at(8), dungeon::Direction::East, dungeon::MoveConstraints::None);
    //Room 9 - Exit
    //Build Entrance and Exit
    _builder->buildEntrance(rooms.at(0), dungeon::Direction::North);
    _builder->buildExit(rooms.at(8), dungeon::Direction::East);

    //Items and creatures
    //Room 3
    _builder->buildCreature(rooms.at(2));
    _builder->buildCreature(rooms.at(4));
    _builder->buildCreature(rooms.at(8));

    _builder->buildItem(rooms.at(2));
    _builder->buildItem(rooms.at(4));
    _builder->buildItem(rooms.at(6));

    std::cout << "Room 6: isPassge(): " << rooms.at(5)->south()->isPassage() << std::endl;

    //Get the DungeonLevel
    _level = _builder->getDungeonLevel();
//    _builder.reset();
}

void Game::createRandomLevel(const std::string& name, const int width, const int height) {
    if (not _builder or height < 1 or height > 4 or width < 1 or width > 4) {
        return;
    }

    if (_level) {
        delete _level;
        _level = nullptr;
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

//    int traversable{0};
//    int impassable{0};
//    int locked{0};
//    for (int i{0}; i < 2147483646; ++i) {
//        int rng = randomInt(10);

//        if (rng == 0) {
//            ++traversable;
//            ++traversable;
//        }
//        if (rng == 1) {
//            ++traversable;
//            ++traversable;
//        }
//        if (rng == 2) {
//            ++traversable;
//            ++impassable;
//        }
//        if (rng == 3) {
//            ++traversable;
//            ++impassable;
//        }
//        if (rng == 4) {
//            ++impassable;
//            ++impassable;
//        }
//        if (rng == 5) {
//            ++locked;
//            ++traversable;
//        }
//        if (rng == 6) {
//            ++locked;
//            ++impassable;
//        }
//        if (rng == 7) {
//            ++traversable;
//            ++locked;
//        }
//        if (rng == 8) {
//            ++locked;
//            ++impassable;
//        }
//        if (rng == 9) {
//            ++locked;
//            ++locked;
//        }

//    }
//    std::cout << "Traversable: " << traversable << std::endl;
//    std::cout << "Impassable: " << impassable << std::endl;
//    std::cout << "Locked: " << locked << std::endl;

    std::vector <std::shared_ptr<dungeon::Room>> rooms{std::vector <std::shared_ptr<dungeon::Room>>()};
    int numOfRooms{width * height};
    rooms.reserve(numOfRooms);
    _builder->BuildDungeonLevel(name, width, height);

    //Build rooms
    for (int i{0}; i < numOfRooms; ++i) {
        rooms.push_back(_builder->buildRoom(i + 1));
    }

    //Build doorways, always building east first (unless in the last column or the only room), then south (unless in the last or only row)
    for (int i{0}; i < numOfRooms; ++i) {
        //roomID and adjacentH (Horizontal) have the same value but i purposely chose to give them separate names
        //to make the algortithm a bit more readable, as they have different meanings and are used in different contexts.
        int roomID{i + 1};
        int adjacentH{i + 1};
        int adjacentV{i + width};

        if (roomID != numOfRooms) {
            //Last Column
            if (roomID % width == 0) {
                //1 x n dungeon
                if (width == 1) {
                    _builder->buildDoorWay(rooms.at(i), rooms.at(adjacentV), dungeon::Direction::South, constraints.at((randomInt(10))));
                }
                //last column and not 1 x n dungeon
                else {
                    if (randomDouble() < 0.50) {
                        _builder->buildDoorWay(rooms.at(i), rooms.at(adjacentV), dungeon::Direction::South, constraints.at((randomInt(10))));
                    }
                }
            }
            //Last row
            else if (roomID > (width * height) - width) {
                _builder->buildDoorWay(rooms.at(i), rooms.at(adjacentH), dungeon::Direction::East, constraints.at((randomInt(10))));
            }
            //All other rooms
            else {
                _builder->buildDoorWay(rooms.at(i), rooms.at(adjacentH), dungeon::Direction::East, constraints.at((randomInt(10))));
                if (height != 1) {
                    if (randomDouble() < 0.69) {
                        _builder->buildDoorWay(rooms.at(i), rooms.at(adjacentV), dungeon::Direction::South, constraints.at((randomInt(10))));
                    }
                }
            }
        }
    }
    //Build Entrance
    int rng{randomInt(width)};
    int entranceRoom = rng;

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
    _builder.reset();
}

const std::ostream& Game::displayLevel(std::ostream& out) const {
    if (not _level) {
        return out;
    }
    std::vector<std::string> dungeon {_level->display()};
    for (std::string row : dungeon ) {
        out << row << std::endl;
    }
}

double Game::randomDouble() {
    return _realDistribution(_randomGenerator);
}
int Game::randomInt(int possibilities) const {
    static std::mt19937 randomGenerator{uint32_t(time(nullptr))};
    static std::uniform_int_distribution<int> distribution{0, RAND_MAX};
    return (distribution(randomGenerator) % possibilities);
}
}

//    _builder.reset();

//    0 = dungeon::MoveConstraints::None
//    1 = dungeon::MoveConstraints::OriginImpassable
//    2 = dungeon::MoveConstraints::DestinationImpassable
//    3 = dungeon::MoveConstraints::OriginImpassable|dungeon::MoveConstraints::DestinationImpassable
//    4 = dungeon::MoveConstraints::OriginLocked
//    6 = dungeon::MoveConstraints::OriginLocked|dungeon|dungeon::MoveConstraints::DestinationImpassable
//    8 = dungeon::MoveConstraints::DestinationLocked
//    9 = dungeon::MoveConstraints::OriginImpassable|dungeon::MoveConstraints::DestinationLocked
//    12= dungeon::MoveConstraints::OriginLocked|dungeon::MoveConstraints::DestinationLocked

//    {None = 0, OriginImpassable = 1, DestinationImpassable = 2, OriginLocked = 4, DestinationLocked = 8};
//    MoveConstraints

//    0000(0) = Open Doorway (Origin and Destination) 		//Traversible/Traversible /
//    0001(1) = One Way Door (Origin) OpenDoorWay(Destination) 	//Impassable/Traversible /
//    0010(2) = Open Doorway (Origin) One Way Door (Destination) 	//Traversible/Impassable /
//    0011(3) = BlockedDoorway (Origin and Destination) 		//Impassable/Impassable /
//    0100(4) = LockedDoor (Origin) OpenDoorway (Destination) 	//Locked/Traversible /
//    0110(6) = LockedDoor (Origin) OneWayDoor (Destination) 		//Locked/Impassable
//    1000(8) = OpenDoorway (Origin) LockedDoor (Destination)  	//Traversible/Locked
//    1001(9) = OneWayDoor (Origin) LockedDoor (Destionation) 	//Impassable/Locked
//    1100(12)= Locked Door (Origin and Destination) 			//Locked/Locked
