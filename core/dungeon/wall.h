#ifndef WALL_H
#define WALL_H

#include "core/dungeon/roomedge.h"

namespace core::dungeon {

class Wall : public RoomEdge  {
  public:
    Wall() = delete;
    Wall(const Wall& other) = delete;
    virtual ~Wall() = default;

    virtual const std::string description() const override = 0; //May not be neccesary to declare this again.
    virtual char displayCharacter() const override;
    virtual bool isPassage() const override;
  protected:
    Wall(Direction direction);
};
}

#endif // WALL_H
