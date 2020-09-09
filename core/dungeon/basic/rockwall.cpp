#include "rockwall.h"

namespace core {
namespace dungeon {
namespace basic {


RockWall::RockWall(Direction direction) : RoomEdge::_direction{direction} {}

RockWall::~RockWall() {

}

const std::string RockWall::description() const {

}
}
}
}
