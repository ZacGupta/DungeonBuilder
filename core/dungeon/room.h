#ifndef ROOM_H
#define ROOM_H

#include "core/creatures/abstractcreature.h"
#include "core/items/item.h"
#include <string>
#include <vector>

namespace core::dungeon {

class RoomEdge;

class Room {
  public:
    Room() = delete;
    Room(const Room& other) = delete;
    Room(const int id);
    virtual ~Room(); //Responsible for cleaning up roomEdge pointers.

    friend std::ostream& operator<<(std::ostream& out, const Room& room);  //operator overload (<<)

    virtual std::string description() const = 0;
    std::vector<std::string> display() const;

    //Getters
    int id() const;
    const core::items::Item& item() const;
    const core::creatures::AbstractCreature& creature() const;
    const RoomEdge& north() const;
    const RoomEdge& south() const;
    const RoomEdge& east() const;
    const RoomEdge& west() const;

    //Setters
    void setItem(const core::items::Item& newItem);
    void setCreature(const core::creatures::AbstractCreature& newCreature);
    void setNorth(const RoomEdge* northEdge);
    void setSouth(const RoomEdge* southEdge);
    void setEast(const RoomEdge* eastEdge);
    void setWest(const RoomEdge* westEdge);
  protected:
    const int _id;
    core::items::Item _item;
    core::creatures::AbstractCreature _creature;
    RoomEdge* _north;
    RoomEdge* _south;
    RoomEdge* _east;
    RoomEdge* _west;
};
enum class Direction : unsigned {North, South, East, West};
}
#endif // ROOM_H
