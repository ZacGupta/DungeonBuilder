#include "roomedge.h"


namespace core {
namespace dungeon {

RoomEdge::RoomEdge() {std::cout << "Created Roomedge" << std::endl;}

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
}
