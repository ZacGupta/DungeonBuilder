#include "magicwall.h"

namespace core::dungeon::magical {

MagicWall::MagicWall(Direction direction) : Wall{direction} {}

const std::string MagicWall::description() const {
    return "a Magic Wall";
}
}
