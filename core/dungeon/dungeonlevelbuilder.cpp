#include "dungeonlevelbuilder.h"
#include <stdlib.h>
#include <time.h>

namespace core::dungeon {

DungeonLevelBuilder::DungeonLevelBuilder() : _level{nullptr} {
    std::cout << "Created DungeonLevelbuilder" << std::endl;
}

DungeonLevelBuilder::~DungeonLevelBuilder() {
    std::cout << "Destroyed DungeonLevelbuilder" << std::endl;
}

void DungeonLevelBuilder::BuildDungeonLevel(const std::string& name, const int width, const int height) {

}

std::shared_ptr<Room> DungeonLevelBuilder::buildRoom(const int id) {

}

void DungeonLevelBuilder::buildDoorWay(std::shared_ptr<Room> origin, std::shared_ptr<Room> destination, const Direction direction, const MoveConstraints constraints) {

}

void DungeonLevelBuilder::buildEntrance(std::shared_ptr<Room> room, const Direction direction) {

}

void DungeonLevelBuilder::buildExit(std::shared_ptr<Room> room, const Direction direction) {

}

void DungeonLevelBuilder::buildItem(std::shared_ptr<Room> room) {

}

void DungeonLevelBuilder::buildCreature(std::shared_ptr<Room> room) {

}

DungeonLevel* DungeonLevelBuilder::getDungeonLevel() {

}

void DungeonLevelBuilder::prototypeItems() {

}

void DungeonLevelBuilder::prototypeCreatures() {

}

int DungeonLevelBuilder::randomInt(int possibilities) const {
    static std::mt19937 randomGenerator{uint32_t(time(nullptr))};
    static std::uniform_int_distribution<int> distribution{0, RAND_MAX};
    return (distribution(randomGenerator) % possibilities);
}

MoveConstraints operator|(const MoveConstraints& origin, const MoveConstraints& destination) {
    return static_cast<MoveConstraints>(static_cast<unsigned>(origin) | static_cast<unsigned>(destination));
}

MoveConstraints operator&(const MoveConstraints& origin, const MoveConstraints& destination) {
    return static_cast<MoveConstraints>(static_cast<unsigned>(origin) & static_cast<unsigned>(destination));
}
}
