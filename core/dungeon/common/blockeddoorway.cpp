#include "blockeddoorway.h"

namespace core::dungeon::common {

BlockedDoorway::BlockedDoorway(Direction direction) : Doorway{direction} {}

const std::string BlockedDoorway::description() const {
    return "a Blocked Doorway to another chamber.";
}

char BlockedDoorway::displayCharacter() const {
    return 'X';
}

bool BlockedDoorway::isEntrance() const {
    return false;
}

bool BlockedDoorway::isExit() const {
    return false;
}
}
