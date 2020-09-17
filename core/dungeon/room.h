#ifndef ROOM_H
#define ROOM_H

#include "core/creatures/abstractcreature.h"
#include "core/items/item.h"
#include <string>
#include <vector>
#include <memory>


namespace core::dungeon {

enum class Direction : unsigned {North, East, South, West};

class RoomEdge;

class Room {
  public:
    Room() = delete;
    Room(const Room& other) = delete;
    virtual ~Room(); //Responsible for cleaning up roomEdge pointers.

    friend std::ostream& operator<<(std::ostream& out, const Room& room);  //operator overload (<<)

    virtual const std::string description() const = 0;
    virtual std::vector<std::string> display() const;

    //Getters
    int id() const;
    const core::items::Item& item() const;
    core::creatures::AbstractCreature& creature() const;
    RoomEdge* north() const;
    RoomEdge* south() const;
    RoomEdge* east() const;
    RoomEdge* west() const;

    //Setters
    void setItem(std::unique_ptr<core::items::Item> newItem);
    void setCreature(std::unique_ptr<core::creatures::AbstractCreature> newCreature);
    void setEdge(RoomEdge* edge, Direction direction);
  protected:
    Room(const int id);
    const int _id;
    std::unique_ptr<core::items::Item> _item;
    std::unique_ptr<core::creatures::AbstractCreature> _creature;
    RoomEdge* _north;
    RoomEdge* _south;
    RoomEdge* _east;
    RoomEdge* _west;
};

}
#endif // ROOM_H
