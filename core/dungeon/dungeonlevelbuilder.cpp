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

void DungeonLevelBuilder::buildDoorWay(Room* origin, Room* destination, const MoveConstraints constraints) {

}

void DungeonLevelBuilder::buildEntrance(Room* room, const Direction direction) {

}

void DungeonLevelBuilder::buildExit(Room* room, const Direction direction) {

}

void DungeonLevelBuilder::buildItem(Room* room) {

}

void DungeonLevelBuilder::buildCreature(Room* room) {

}

const DungeonLevel* DungeonLevelBuilder::getDungeonLevel() const {

}

void DungeonLevelBuilder::prototypeItems() {

}

void DungeonLevelBuilder::prototypeCreatures() {

}

}
