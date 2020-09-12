#include "magicdungeonlevel.h"

namespace core::dungeon::magical {

MagicDungeonLevel::MagicDungeonLevel(const std::string& name, int width, int height) : DungeonLevel{name, width, height} {}

const std::string MagicDungeonLevel::description() const {
    return "Magic Dungeon";
}

}
