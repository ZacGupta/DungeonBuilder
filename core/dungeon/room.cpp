#include "room.h"
#include "core/dungeon/roomedge.h"

namespace core::dungeon {

Room::Room(const int id) : _id{id} {
    std::cout << "Created Room" << std::endl;
}

Room::~Room() {
    delete _north;
    delete _south;
    delete _east;
    delete _west;
    std::cout << "Destroyed Room" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Room& room) {
    return out << room.description();
}

std::vector<std::string> Room::display() const {
    return std::vector<std::string>();
}

int Room::id() const {
    return _id;
}

const items::Item& Room::item() const {
    return _item;
}

const creatures::AbstractCreature& Room::creature() const {
    return _creature;
}

const RoomEdge& Room::north() const {
    return *_north;
}

const RoomEdge& Room::south() const {
    return *_south;
}

const RoomEdge& Room::east() const {
    return *_east;
}

const RoomEdge& Room::west() const {
    return *_west;
}

void Room::setItem(const items::Item& newItem) {
    _item = newItem;
}

void Room::setCreature(const creatures::AbstractCreature& newCreature) {
    _creature = newCreature;
}

void Room::setNorth(const RoomEdge* northEdge) {
    _north = northEdge;
}

void Room::setSouth(const RoomEdge* southEdge) {
    _south = southEdge;
}

void Room::setEast(const RoomEdge* eastEdge) {
    _east = eastEdge;
}

void Room::setWest(const RoomEdge* westEdge) {
    _west = westEdge;
}
}

