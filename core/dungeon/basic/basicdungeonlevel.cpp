#include "basicdungeonlevel.h"

namespace core::dungeon::basic {

BasicDungeonLevel::BasicDungeonLevel(const std::string& name, int width, int height) : DungeonLevel{name, width, height} {}

const std::string BasicDungeonLevel::description() const {
    return "Basic Dungeon";
}

}
