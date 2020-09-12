#include "room.h"
#include "core/dungeon/roomedge.h"

namespace core::dungeon {

Room::Room(const int id) : _id{id}, _item{nullptr}, _creature{nullptr}, _north{nullptr}, _south{nullptr}, _east{nullptr}, _west{nullptr} {
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
    //Base template
    std::string top = "+---- ----+";
    const std::string offCentreTop = "|         |";
    std::string centre = "           ";
    const std::string offCentreBottom = "|         |";
    std::string bottom = "+---- ----+";


    //Fill in the relevant RoomEdge characters
    top[5] = _north->displayCharacter();
    bottom[5] = _south->displayCharacter();
    centre[10] = _east->displayCharacter();
    centre[0] = _west->displayCharacter();

    //Fill centre of the room (Creature/Loot Item)
    if (_creature) {
        centre[4] = _creature->displayCharacter();
        if (_creature->isBoss()) {
            centre[5] = '*';
        }
    }
    if (_item) {
        centre[6] = _item->displayCharacter();
    }
    return std::vector<std::string> {top, offCentreTop, centre, offCentreBottom, bottom};
}

int Room::id() const {
    return _id;
}

const items::Item& Room::item() const {
    return *_item;
}

const creatures::AbstractCreature& Room::creature() const {
    return *_creature;
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

void Room::setItem(std::unique_ptr<core::items::Item> newItem) {
    _item = std::move(newItem);
}

void Room::setCreature(std::unique_ptr<core::creatures::AbstractCreature> newCreature) {
    _creature = std::move(newCreature);
}

void Room::setEdge(const RoomEdge* edge, Direction direction) {
    switch (direction) {
    case (Direction::North):
        if (_north) {
            delete _north;
        }
        _north = edge;
        break;
    case (Direction::South):
        if (_south) {
            delete _south;
        }
        _south = edge;
        break;
    case (Direction::East):
        if (_east) {
            delete _east;
        }
        _east = edge;
        break;
    case (Direction::West):
        if (_west) {
            delete _west;
        }
        _west = edge;
    }
}
}

