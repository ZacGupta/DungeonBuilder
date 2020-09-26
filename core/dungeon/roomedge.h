#ifndef ROOMEDGE_H
#define ROOMEDGE_H

#include "core/dungeon/room.h"
#include <string>

namespace core::dungeon {

class RoomEdge {
  public:
    RoomEdge() = delete;
    RoomEdge(const RoomEdge& other) = delete;
    virtual ~RoomEdge() = default;

    friend std::ostream& operator<<(std::ostream& out, const RoomEdge& roomEdge);
    //!< @brief Overloads the << operator to describe the RoomEdge.

    virtual const std::string description() const = 0;
    //!< @brief Returns a description of itself when overridden by a derieved class.

    virtual char displayCharacter() const = 0;
    //!< @brief Returns the specific display character when this method is overridden by a derieved class.

    virtual bool isPassage() const = 0;
    //!< @brief Returns true if the RoomEdge can be passed through.

    const Direction& getDirection() const;
    //!< @brief Returns the location of itself (North, South, East or West).

    Direction oppositeDirection() const;
    //!< @brief Returns the opposite direction of its own direction.

  protected:
    RoomEdge (Direction _direction);
    Direction _direction;

};
}

#endif // ROOMEDGE_H
