#include "blockeddoorway.h"

namespace core::dungeon::common {

BlockedDoorway::BlockedDoorway(Direction direction) : Doorway{direction} {
    std::cout << "Created BlockedDoorway" << std::endl;
}

BlockedDoorway::~BlockedDoorway() {
    std::cout << "Destroyed BlockedDoorWay" << std::endl;
}

const std::string BlockedDoorway::description() const {
    return "a Blocked Doorway to another chamber";
}

char BlockedDoorway::displayCharacter() const {
    return 'X';
}
}
