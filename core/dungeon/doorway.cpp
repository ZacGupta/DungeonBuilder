#include "doorway.h"

namespace core::dungeon {

Doorway::Doorway() {
    std::cout << "Created Doorway" << std::endl;
}

Doorway::Doorway(Direction direction) : RoomEdge{direction} {}

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
