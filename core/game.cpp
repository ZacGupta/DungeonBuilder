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

//void Game::setDungeonType(core::dungeon::DungeonLevelBuilder* builder) {
//    if (_builder) {
//        delete builder;
//        _builder = nullptr;
//    }
//    _builder = builder;
//}

void Game::setDungeonType(std::unique_ptr<dungeon::DungeonLevelBuilder> builder) {
    if (_level) {
        delete _level;
    }
    _builder = std::move(builder);
}

void Game::createExampleLevel() {
    std::vector <dungeon::Room*> rooms;
    _builder->BuildDungeonLevel("Example", 1, 2);
    rooms.push_back(_builder->buildRoom(1));
    rooms.push_back(_builder->buildRoom(2));
    _builder->buildDoorWay(rooms.at(0), rooms.at(1), dungeon::Direction::East, dungeon::MoveConstraints::DestinationImpassable);
    _level = _builder->getDungeonLevel();
}

void Game::createRandomLevel(const std::string& name, const int width, const int height) {
    if (_level) {
        delete _level;
        _level = nullptr;
    }
    _builder->BuildDungeonLevel(name, width, height);
    _level = _builder->getDungeonLevel();
}

std::vector<std::vector<std::string>> Game::displayLevel() const {
    std::vector<std::vector<std::string>> dungeon;
    std::vector<std::string> room;
    int rows = _level->width();
    int cols = _level->height();
    int numOFRooms = _level->numberOfRooms();

    int i = 0;
    //Outer loop for each room
    for (int i = 0; i < numOFRooms; ++i ) {
        int roomID = i + 1;
        room = _level->retrieveRoom(i + 1)->display();
        std::vector<std::string> newRoom = std::vector<std::string>();

        //Inner loop for each 'line' in a room.
        for (int j = 0; j < 6; ++j) {
            std::string line;
            //To stay in bounds of the vector.
            if (j < 5) {
                line = room.at(j);
            }
            //Top/offcentre//bottom
            if (j != 2 and j != 5) {
                line += "  ";
                newRoom.push_back(line);
            }
            //Horiontal-center & not the in the last column.
            if (j == 2 and roomID % cols != 0) {
                //If room is a passage.
                if (_level->retrieveRoom(1)->east().isPassage()) {
                    line += "--";
                    newRoom.push_back(line);
                } else {
                    line += "  ";
                    newRoom.push_back(line);
                }
            } else if (j == 2) {
                line += "  ";
                newRoom.push_back(line);
            }
            //The gap between rows & room not in the last row.
            if (j == 5 && roomID < (cols - 1) * rows) {
                //If room is a passage.
                if (_level->retrieveRoom(1)->south().isPassage()) {
                    line += "     |       ";
                    newRoom.push_back(line);
                } else {
                    line += "             ";
                    newRoom.push_back(line);
                }
            }
        }
        dungeon.push_back(newRoom);
    }
    return dungeon;
}

double Game::randomDouble() {
    return _realDistribution(_randomGenerator);
}


}
