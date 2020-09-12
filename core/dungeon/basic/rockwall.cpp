#include "rockwall.h"

namespace core::dungeon::basic {


RockWall::RockWall(Direction direction) : Wall{direction} {}

const std::string RockWall::description() const {
    return "a Rock Wall";
}

}
