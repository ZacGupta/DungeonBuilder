#include "doorway.h"

namespace core::dungeon {

Doorway::Doorway(Direction direction) : RoomEdge{direction}, _opposite{nullptr} {
    if (_opposite) std::cout << "Opposite on construction" << std::endl;

    std::cout << "Created Doorway with direction" << std::endl;
}

Doorway::~Doorway() {
    std::cout << "Destroyed Doorway" << std::endl;
}

void Doorway::connect(const Doorway* opposite) {
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
    if (_opposite == nullptr) {
        return false;
    }
    else {
        return true;
    }
}
}
