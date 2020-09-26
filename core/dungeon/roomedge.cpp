#include "roomedge.h"


namespace core::dungeon {

RoomEdge::RoomEdge(Direction direction) : _direction{direction} {}

std::ostream& operator<<(std::ostream& out, const RoomEdge& roomEdge) {
    return out << roomEdge.description();
}

const Direction& RoomEdge::getDirection() const {
    return _direction;
}

Direction RoomEdge::oppositeDirection() const {
    switch (_direction) {
    case (Direction::North):
        return Direction::South;
    case (Direction::South):
        return Direction::North;
    case (Direction::East):
        return Direction::West;
    case (Direction::West):
        return Direction::East;
    }
}
}
