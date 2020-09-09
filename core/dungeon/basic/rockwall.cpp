#include "rockwall.h"

namespace core::dungeon::basic {


RockWall::RockWall(Direction direction) : Wall{direction} {
    std::cout << "Created RockWall" << std::endl;
}

RockWall::~RockWall() {
    std::cout << "Destroyed RockWall" << std::endl;
}

const std::string RockWall::description() const {
    return "a Rock Wall";
}

}
