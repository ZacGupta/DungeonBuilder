#include "doorway.h"

namespace core::dungeon {

Doorway::Doorway(Direction direction) : RoomEdge{direction} {

    std::cout << "Created Doorway with direction" << std::endl;
}

Doorway::~Doorway() {
    std::cout << "Destroyed Doorway" << std::endl;
}

void Doorway::connect(const Doorway* opposite) {
    if (opposite) {
        _opposite = opposite;
    }
}

bool Doorway::isEntrance() const {
    return false;
}

bool Doorway::isExit() const {
    return false;
}

bool Doorway::isPassage() const {
    if (_opposite) {
        return true;
    }
    else {
        return false;
    }
}
}
