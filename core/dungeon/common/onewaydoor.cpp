#include "onewaydoor.h"

namespace core::dungeon::common {


OneWayDoor::OneWayDoor(Direction direction) : Doorway{direction} {
    std::cout << "Created OneWayDoor" << std::endl;
}

OneWayDoor::~OneWayDoor() {
    std::cout << "Destroyed OneWayDoor" << std::endl;
}

const std::string OneWayDoor::description() const {
    return "a One Way Door";
}

char OneWayDoor::displayCharacter() const {
    if (_direction == Direction::North) {
        return 'v';
    } else if (_direction == Direction::South) {
        return '^';
    } else if (_direction == Direction::East) {
        return '>';
    } else {
        return '>';
    }
}
}
