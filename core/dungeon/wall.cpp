#include "wall.h"

namespace core {
namespace dungeon {

Wall::Wall() {
    std::cout << "Created Wall" << std::endl;
}

Wall::Wall(Direction direction) : RoomEdge{direction} {
        std::cout << "Created Wall with Direction" << std::endl;
}

Wall::~Wall() {
    std::cout << "Destroyed Wall" << std::endl;
}

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
}
