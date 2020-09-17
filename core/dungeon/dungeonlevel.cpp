#include "dungeonlevel.h"
#include "core/dungeon/roomedge.h"

namespace core::dungeon {

DungeonLevel::DungeonLevel(const std::string& name, int width, int height) : _name{name}, _width{width}, _height{height}, _numberOfRooms{height * width} {
    _rooms.reserve(_numberOfRooms);
}

std::ostream& operator<<(std::ostream& out, const DungeonLevel& dungeonLevel) {
    return out << dungeonLevel.description();
}

bool DungeonLevel::addRoom(std::shared_ptr<Room> room) {
    if (room and _rooms.size() < static_cast<unsigned>(_numberOfRooms)) {
        _rooms.push_back(room);
        return true;
    }
    return false;
}


std::shared_ptr<Room> DungeonLevel::retrieveRoom(int id) const {
    if (id < 1 or id > numberOfRooms()) {
        return nullptr;
    }
    return _rooms.at(id - 1);
}

int DungeonLevel::width() const {
    return _width;
}

int DungeonLevel::height() const {
    return _height;
}

int DungeonLevel::numberOfRooms() const {
    return _numberOfRooms;
}

const std::string& DungeonLevel::name() const {
    return _name;
}

const std::vector<std::string> DungeonLevel::display() const {
    std::vector<std::vector<std::string>> dungeon{buildDisplay()};
    std::vector<std::string> newDungeon{std::vector<std::string>()};

    if (dungeon.size() == 0) {
        return std::vector<std::string>();
    }
    int rows{_height};
    int cols{_width};
    unsigned maxLoop{(static_cast<unsigned>(rows) * 6) - 1};

    //For each row in the dungeon
    for (int i{0}; i < rows; ++i) {
        //For each line inside a row (including the gap between rows)
        for (int j{0}; j < 6; ++j) {
            int lastRoom{i* cols + cols};
            std::string line{""};
            //For each room in the row, concatenate.
            for (int k{i * cols}; k < lastRoom; ++k) {
                if (newDungeon.size() != maxLoop) {
                    line += dungeon.at(k).at(j);
                }
            }
            newDungeon.push_back(line);
        }
    }
    return newDungeon;
}

std::vector<std::vector<std::string>> DungeonLevel::buildDisplay() const {
    std::vector<std::vector<std::string>> dungeon;
    int rows{_height};
    int cols{_width};
    int numOFRooms{_numberOfRooms};

    //Outer loop for each room
    for (int i{0}; i < numOFRooms; ++i ) {
        int roomID{i + 1};
        std::vector<std::string> room{_rooms.at(i)->display()};
        std::vector<std::string> newRoom{std::vector<std::string>()};

        //Inner loop for each 'line' in a room.
        for (int j{0}; j < 6; ++j) {
            std::string line{""};
            //To stay in bounds of the vector.
            if (j < 5) {
                line = room.at(j);
            }
            //Top/offcentre//bottom
            if (j != 2 and j != 5) {
                line += "  ";
                newRoom.push_back(line);
            }
            //Horiontal-centre & not the in the last column.
            if (j == 2 and roomID % cols != 0) {
                if (_rooms.at(i)->east()->isPassage()) {
                    line += "--";
                    newRoom.push_back(line);
                } else {
                    line += "  ";
                    newRoom.push_back(line);
                }
            } else if (j == 2 and roomID % cols == 0) { //In the last column
                newRoom.push_back(line);
            }
            //Insert vertical gap between the rooms if room is not in the last row.
            if (j == 5 and roomID <= (rows * cols) - cols) {
                if (_rooms.at(i)->south()->isPassage()) {
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

}
