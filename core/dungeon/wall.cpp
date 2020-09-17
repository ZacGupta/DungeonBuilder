#include "wall.h"

namespace core::dungeon {

Wall::Wall(Direction direction) : RoomEdge{direction} {}

char Wall::displayCharacter() const {
    if (_direction == Direction::North or _direction == Direction::South) {
        return '-';
    } else {
        return '|';
    }
}

bool Wall::isPassage() const {
    return false;
}


}
