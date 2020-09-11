#include "dungeonlevel.h"
#include "core/dungeon/basic/rockchamber.h"

namespace core::dungeon {

DungeonLevel::DungeonLevel(const std::string& name, int width, int height) : _name{name}, _width{width}, _height{height}, _numberOfRooms{height * width} {
    _rooms.reserve(_numberOfRooms);
    std::cout << "Created DungeonLevel" << std::endl;
}

DungeonLevel::~DungeonLevel() {
    for (Room* room : _rooms) {
        delete room;
    }
    std::cout << "Destroyed DungeonLevel" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const DungeonLevel& dungeonLevel) {
    return out << dungeonLevel.description();
}

bool DungeonLevel::addRoom(Room* room) {
    if (room and _rooms.size() < static_cast<unsigned>(_numberOfRooms)) {
        _rooms.push_back(room);
        std::cout << "Added room" << room->id() <<std::endl;
        return true;
    }
    std::cout << "Failed to add" << room->id() << std::endl;
    return false;
}

Room* DungeonLevel::retrieveRoom(int id) const {
    if (id < 1 or id > numberOfRooms()) {
        return nullptr;
    }
    return _rooms.at(id -1);
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

const std::vector<std::string>& DungeonLevel::display() const {
    return _display;
}

}
