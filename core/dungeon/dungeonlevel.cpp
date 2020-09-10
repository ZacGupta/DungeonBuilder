#include "dungeonlevel.h"
#include "core/dungeon/basic/rockchamber.h"

namespace core::dungeon {

DungeonLevel::DungeonLevel(const std::string& name, int width, int height) : _name{name}, _width{width}, _height{height}, _numberOfRooms{height * width} {
    std::cout << "Created DungeonLevel" << std::endl;
}

DungeonLevel::~DungeonLevel() {
    std::cout << "Destroyed DungeonLevel" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const DungeonLevel& dungeonLevel) {
    return out << dungeonLevel.description();
}

bool DungeonLevel::addRoom(const Room* room) {
    room = new core::dungeon::basic::RockChamber{1};
    return false;
}

Room* DungeonLevel::retrieveRoom(int) const {
    return new core::dungeon::basic::RockChamber{1};
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
