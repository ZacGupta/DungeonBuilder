#include "doorway.h"

namespace core::dungeon {

Doorway::Doorway(Direction direction) : RoomEdge{direction}, _opposite{nullptr} {
    std::cout << "Created Doorway with direction" << std::endl;
}

Doorway::~Doorway() {
    //Potentially unneccesary if all rooms are destroyed at once since the pointer will go out of scope and the _opposites,
    //and every room being pointed to by each _opposite will be destroyed by ~Room().
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
