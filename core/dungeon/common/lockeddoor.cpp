#include "lockeddoor.h"

namespace core::dungeon::common {


LockedDoor::LockedDoor(Direction direction) : Doorway{direction} {}

const std::string LockedDoor::description() const {
    return "a Locked Door to another chamber";
}

char LockedDoor::displayCharacter() const {
    return '@';
}

bool LockedDoor::isEntrance() const {
    return false;
}

bool LockedDoor::isExit() const {
    return false;
}
}
