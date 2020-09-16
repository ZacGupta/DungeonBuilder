#include "doorway.h"

namespace core::dungeon {

Doorway::Doorway(Direction direction) : RoomEdge{direction}, _opposite{nullptr} {
    std::cout << "Created Doorway" << std::endl;
}

Doorway::~Doorway() {
    if (_opposite) {
        _opposite->_opposite = nullptr;
    }
    std::cout << "Destroyed Doorway" << std::endl;
}

void Doorway::connect(Doorway* opposite) {
    if (opposite and not _opposite) {
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
