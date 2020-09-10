#include "dungeonlevelbuilder.h"

namespace core::dungeon {

void DungeonLevelBuilder::BuildDungeonLevel(const std::string& name, const int width, const int height) const {}

Room* DungeonLevelBuilder::buildRoom(const int id) const {}

void DungeonLevelBuilder::buildDoorWay(const Room& origin, const Room& destination) const {}

void DungeonLevelBuilder::buildEntrance(const Room& room, const Direction direction) const {}

void DungeonLevelBuilder::buildExit(const Room& room, const Direction direction) const {}

void DungeonLevelBuilder::buildItem(const Room& room) const {}

void DungeonLevelBuilder::buildCreature(const Room& room) const {}

const DungeonLevel DungeonLevelBuilder::getDungeonLevel() const {}
}
