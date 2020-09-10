#include "magicdungeonlevel.h"

namespace core::dungeon::magical {

MagicDungeonLevel::MagicDungeonLevel(const std::string& name, int width, int height) : DungeonLevel{name, width, height} {
    std::cout << "Created MagicDungeonLevel" << std::endl;;
}

MagicDungeonLevel::~MagicDungeonLevel() {
    std::cout << "Destroyed MagicDungeonLevel" << std::endl;;
}

const std::string MagicDungeonLevel::description() const {
    return "Magic Dungeon";
}

}
