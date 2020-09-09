#ifndef ROOM_H
#define ROOM_H

#include "core/creatures/abstractcreature.h"
#include "core/items/item.h"
#include <string>
#include <vector>

namespace core {
namespace dungeon {

class RoomEdge;

class Room {
  public:
    Room() = delete;
    Room(const Room& other) = delete;
    Room(const int id);
    virtual ~Room();

    friend std::ostream& operator<<(std::ostream& out, const Room& room);  //operator overload (<<)

    virtual std::string description() const = 0;
    std::vector<std::string> display() const;

    int id() const;

    const core::items::Item& item() const;
    void setItem(const core::items::Item& newItem);

    const core::creatures::AbstractCreature& creature() const;
    void setCreature(const core::creatures::AbstractCreature& newCreature);

    const RoomEdge& getNorth() const;
    const RoomEdge& getSouth() const;
    const RoomEdge& getEast() const;
    const RoomEdge& getNWest() const;

    //Does this require a pointer or reference?
    void setNorth(const RoomEdge* northEdge);
    void setSouth(const RoomEdge* southEdge);
    void setEast(const RoomEdge* eastEdge);
    void setWest(const RoomEdge* westEdge);

  private:
    const int _id;
    core::items::Item _item;
    core::creatures::AbstractCreature _creature;
    RoomEdge* _north;
    RoomEdge* _south;
    RoomEdge* _east;
    RoomEdge* _west;
};
enum class Direction : unsigned {North, South, East, West}; // Make sure this is in the correct scope
}
}
#endif // ROOM_H
