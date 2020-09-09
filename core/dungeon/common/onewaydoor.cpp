#include "onewaydoor.h"

namespace core::dungeon::common {


OneWayDoor::OneWayDoor(Direction direction) : Doorway{direction}, _isEntrance{false}, _isExit{false} {
    std::cout << "Created OneWayDoor" << std::endl;
}

OneWayDoor::~OneWayDoor() {
    std::cout << "Destroyed OneWayDoor" << std::endl;
}

const std::string OneWayDoor::description() const {
    if (_isEntrance) {
        return "the entrance to the dungeon level (One Way Door)";
    } else if (_isExit) {
        return "an EXIT (One Way Door)";
    } else {
        return "a One Way Door";
    }
}

char OneWayDoor::displayCharacter() const {
    if (_isEntrance) {
        return 'I';
    } else if (_isExit) {
        return 'O';
    } else {
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

bool OneWayDoor::isEntrance() const {
    return _isEntrance;
}

bool OneWayDoor::isExit() const {
    return _isExit;
}

void OneWayDoor::markAsEntrance() {
    _isEntrance = true;
}

void OneWayDoor::markAsExit() {
    _isExit = true;
}

}
