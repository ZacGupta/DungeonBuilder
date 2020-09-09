#include "roomedge.h"


namespace core::dungeon {

RoomEdge::RoomEdge(Direction direction) : _direction{direction} {
    std::cout << "Created RoomEdge with Direction" << std::endl;
}

RoomEdge::~RoomEdge() {
    std::cout << "Destroyed RoomEdge" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const RoomEdge& roomEdge) {
    return out << roomEdge.description();
}

const Direction& RoomEdge::getDirection() const {
    return _direction;
}

}
