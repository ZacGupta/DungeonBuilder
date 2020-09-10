#ifndef ROOM_H
#define ROOM_H

#include "core/creatures/abstractcreature.h"
#include "core/items/item.h"
#include <string>
#include <vector>
#include <memory>
#include <iostream> //DELETE THIS

namespace core::dungeon {

class RoomEdge;

class Room {
  public:
    Room() = delete;
    Room(const Room& other) = delete;
    virtual ~Room(); //Responsible for cleaning up roomEdge pointers.

    friend std::ostream& operator<<(std::ostream& out, const Room& room);  //operator overload (<<)

    virtual const std::string description() const = 0;
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
    void setItem(std::unique_ptr<core::items::Item> newItem);
    void setCreature(std::unique_ptr<core::creatures::AbstractCreature> newCreature);
    void setNorth(const RoomEdge* northEdge);
    void setSouth(const RoomEdge* southEdge);
    void setEast(const RoomEdge* eastEdge);
    void setWest(const RoomEdge* westEdge);
  protected:
    Room(const int id);
    const int _id;
    std::unique_ptr<core::items::Item> _item;
    std::unique_ptr<core::creatures::AbstractCreature> _creature;
    const RoomEdge* _north;
    const RoomEdge* _south;
    const RoomEdge* _east;
    const RoomEdge* _west;
};
enum class Direction : unsigned {North, South, East, West};
}
#endif // ROOM_H
