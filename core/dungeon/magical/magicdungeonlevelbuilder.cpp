#include "magicdungeonlevelbuilder.h"

namespace core::dungeon::magical {

void MagicDungeonLevelBuilder::BuildDungeonLevel(const std::string& name, const int width, const int height) const {

}

Room* MagicDungeonLevelBuilder::buildRoom(const int id) const {

}

void MagicDungeonLevelBuilder::buildDoorWay(const Room& origin, const Room& destination) const {

}

void MagicDungeonLevelBuilder::buildEntrance(const Room& room, const Direction direction) const {

}

void MagicDungeonLevelBuilder::buildExit(const Room& room, const Direction direction) const {

}

void MagicDungeonLevelBuilder::buildItem(const Room& room) const {

}

void MagicDungeonLevelBuilder::buildCreature(const Room& room) const {

}

const DungeonLevel MagicDungeonLevelBuilder::getDungeonLevel() const {

}

}
