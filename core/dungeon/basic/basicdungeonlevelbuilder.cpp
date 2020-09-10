#include "basicdungeonlevelbuilder.h"

namespace core::dungeon::basic {

void BasicDungeonLevelBuilder::BuildDungeonLevel(const std::string& name, const int width, const int height) const {

}

Room* BasicDungeonLevelBuilder::buildRoom(const int id) const {

}

void BasicDungeonLevelBuilder::buildDoorWay(const Room& origin, const Room& destination) const {

}

void BasicDungeonLevelBuilder::buildEntrance(const Room& room, const Direction direction) const {

}

void BasicDungeonLevelBuilder::buildExit(const Room& room, const Direction direction) const {

}

void BasicDungeonLevelBuilder::buildItem(const Room& room) const {

}

void BasicDungeonLevelBuilder::buildCreature(const Room& room) const {

}

const DungeonLevel BasicDungeonLevelBuilder::getDungeonLevel() const {

}

}
