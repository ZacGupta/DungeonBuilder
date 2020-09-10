#include "basicdungeonlevel.h"

namespace core::dungeon::basic {

BasicDungeonLevel::BasicDungeonLevel(const std::string& name, int width, int height) : DungeonLevel{name, width, height} {
    std::cout << "Created BasicDungeonLevel" << std::endl;
}

BasicDungeonLevel::~BasicDungeonLevel() {
    std::cout << "Created BasicDungeonLevel" << std::endl;
}

const std::string BasicDungeonLevel::description() const {
    return "Basic Dungeon";
}

}
