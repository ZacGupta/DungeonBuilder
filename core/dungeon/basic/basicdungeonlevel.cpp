#include "basicdungeonlevel.h"

namespace core::dungeon::basic {

BasicDungeonLevel::BasicDungeonLevel(const std::string& name, int width, int height) : DungeonLevel{name, width, height} {}

const std::string BasicDungeonLevel::description() const {
    return _name + "\nSize: " + std::to_string(_width) + " x " + std::to_string(_height) + "\nType: Dark Cave (Basic Dungeon)";
}

}
