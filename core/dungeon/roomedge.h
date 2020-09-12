#ifndef ROOMEDGE_H
#define ROOMEDGE_H

#include "core/dungeon/room.h"
#include <string>
#include "iostream"//DELETE THIS

namespace core::dungeon {

class RoomEdge {
  public:
    RoomEdge() = delete;
    RoomEdge(const RoomEdge& other) = delete;
    virtual ~RoomEdge() = default;

    friend std::ostream& operator<<(std::ostream& out, const RoomEdge& roomEdge);  //operator overload (<<)

    virtual const std::string description() const = 0;
    virtual char displayCharacter() const = 0;
    virtual bool isPassage() const = 0;
    const Direction& getDirection() const;
    const Direction oppositeDirection() const;
  protected:
    RoomEdge (Direction _direction);
    Direction _direction;

};
}

#endif // ROOMEDGE_H
