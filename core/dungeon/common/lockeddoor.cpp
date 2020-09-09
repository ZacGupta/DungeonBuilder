#include "lockeddoor.h"

namespace core::dungeon::common {


LockedDoor::LockedDoor(Direction direction) : Doorway{direction} {
    std::cout << "Created Locked Door" << std::endl;
}

LockedDoor::~LockedDoor() {
    std::cout << "Destroyed Locked Door" << std::endl;
}

const std::string LockedDoor::description() const {
    return "a Locked Door";
}

char LockedDoor::displayCharacter() const {
    return '@';
}
}
