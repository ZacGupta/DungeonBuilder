#include "dungeonlevelbuilder.h"

namespace core::dungeon {

DungeonLevelBuilder::DungeonLevelBuilder() : _level{nullptr} {
    std::cout << "Created DungeonLevelbuilder" << std::endl;
}

DungeonLevelBuilder::~DungeonLevelBuilder() {
    std::cout << "Destroyed DungeonLevelbuilder" << std::endl;
}

void DungeonLevelBuilder::BuildDungeonLevel(const std::string& name, const int width, const int height) {

}

Room* DungeonLevelBuilder::buildRoom(const int id) {

}

void DungeonLevelBuilder::buildDoorWay(Room* origin, Room* destination, const Direction direction, const MoveConstraints constraints) {

}

void DungeonLevelBuilder::buildEntrance(Room* room, const Direction direction) {

}

void DungeonLevelBuilder::buildExit(Room* room, const Direction direction) {

}

void DungeonLevelBuilder::buildItem(Room* room) {

}

void DungeonLevelBuilder::buildCreature(Room* room) {

}

DungeonLevel* DungeonLevelBuilder::getDungeonLevel() const {

}

void DungeonLevelBuilder::prototypeItems() {

}

void DungeonLevelBuilder::prototypeCreatures() {

}

int DungeonLevelBuilder::randomInt(double possibilities) {
    std::uniform_real_distribution<double> realDistribution{0, possibilities};
    std::mt19937 randomGenerator{uint32_t(time(nullptr))};
    return realDistribution(randomGenerator);

}

MoveConstraints operator|(const MoveConstraints& o, const MoveConstraints& d) {
    return static_cast<MoveConstraints>(static_cast<unsigned>(o) | static_cast<unsigned>(d));
}

MoveConstraints operator&(const MoveConstraints& o, const MoveConstraints& d) {
    return static_cast<MoveConstraints>(static_cast<unsigned>(o) | static_cast<unsigned>(d));
}

std::ostream& operator<<(std::ostream& out, const MoveConstraints& c) {
    switch(static_cast<unsigned>(c)) {
    case 0:
        out << "0";
        break;
    case 1:
        out << "1";
        break;
    case 2:
        out << "2";
    case 3:
        out << "3";
        break;
    case 4:
        out << "4";
        break;
    case 8:
        out << "8";
        break;
    case 12:
        out << "12";
        break;
    }
    return out;
}

}
