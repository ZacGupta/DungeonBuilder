#include "magicwall.h"

namespace core::dungeon::magical {

MagicWall::~MagicWall() {
    std::cout << "Destroyed MagicWall" << std::endl;
}

MagicWall::MagicWall(Direction direction) : Wall{direction} {
    std::cout << "Created MagicalWall" << std::endl;

}

const std::string MagicWall::description() const {
    return "a Magic Wall";
}
}
