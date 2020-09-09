#include "doorway.h"

namespace core::dungeon {

Doorway::Doorway(Direction direction) : RoomEdge{direction} {

    std::cout << "Created Doorway with direction" << std::endl;
}

Doorway::~Doorway() {
    if (_opposite) {
        _opposite = nullptr;
        std::cout << "Opposite is now null" << std::endl;
    }
    std::cout << "Destroyed Doorway" << std::endl;
}

void Doorway::connect(const Doorway* opposite) {
    if (opposite) {
        _opposite = opposite;
    }
}

const Doorway& Doorway::opposite() const {
    return *_opposite;
}

bool Doorway::isEntrance() const {
    return false;
}

bool Doorway::isExit() const {
    return false;
}

bool Doorway::isPassage() const {
    if (_opposite == nullptr) {
        return false;
    }
    else {
        return true;
    }
}
}
