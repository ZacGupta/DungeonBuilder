#include "magicdungeonlevel.h"

namespace core::dungeon::magical {

MagicDungeonLevel::MagicDungeonLevel(const std::string& name, int width, int height) : DungeonLevel{name, width, height} {}

const std::string MagicDungeonLevel::description() const {
    return _name + "\nSize: " + std::to_string(_width) + " x " + std::to_string(_height) + "\nType: Enchanted Cave (Magic Dungeon)";
}
}
