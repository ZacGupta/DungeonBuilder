#include "doorway.h"

namespace core::dungeon {

Doorway::Doorway(Direction direction) : RoomEdge{direction} {
    std::cout << "Created Doorway with direction" << std::endl;
}

Doorway::~Doorway() {
    std::cout << "Destroyed Doorway" << std::endl;
}

void Doorway::connect(const Doorway* opposite) {
    _opposite = opposite;
}

bool Doorway::isPassage() const {
    return not _isEntrance or _isExit;
}

void Doorway::markAsEntrance() {
    _isEntrance = true;
}

void Doorway::markAsExit() {
    _isExit = true;
}

bool Doorway::isEntrance() const {
    return _isEntrance;
}

bool Doorway::isExit() const {
    return _isExit;
}

}
