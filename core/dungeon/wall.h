#ifndef WALL_H
#define WALL_H

#include "core/dungeon/roomedge.h"

namespace core::dungeon {

class Wall : public RoomEdge  {
  public:
    Wall() = delete;
    Wall(const Wall& other) = delete;
    virtual ~Wall() = default;

    virtual const std::string description() const override = 0;
    //!< @brief Returns a description of itself.

    virtual char displayCharacter() const override;
    //!< @brief Returns its own specific display character.

    virtual bool isPassage() const override;
    //!< @brief Always returns false for this class.

  protected:
    Wall(Direction direction);
};
}

#endif // WALL_H
