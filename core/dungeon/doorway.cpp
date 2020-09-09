#include "doorway.h"

namespace core::dungeon {

Doorway::Doorway() {
    std::cout << "Created Doorway" << std::endl;
}

Doorway::Doorway(Direction direction) : RoomEdge{direction} {}

Doorway::~Doorway() {
    std::cout << "Destroyed Doorway" << std::endl;
}

std::ostream& core::dungeon::Doorway::operator<<(std::ostream& out, const Doorway& doorway) {

}

void Doorway::connect(const Doorway* opposite) {

}

bool Doorway::isEntrance() const {

}

bool Doorway::isExit() const {

}



}
