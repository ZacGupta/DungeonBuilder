#include "opendoorway.h"

namespace core::dungeon::common {


OpenDoorway::OpenDoorway(Direction direction) : Doorway(direction) {
    std::cout << "Created OpenDoorWay" << std::endl;
}

OpenDoorway::~OpenDoorway() {
    std::cout << "Destroyed OpenDoorWay" << std::endl;
}

const std::string OpenDoorway::description() const {
    return "an Open Doorway";
}

char OpenDoorway::displayCharacter() const {
    if (_direction == Direction::North) {
        return '^';
    } else if (_direction == Direction::South) {
        return 'v';
    } else if (_direction == Direction::East) {
        return '>';
    } else {
        return '<';
    }
}
}
