#ifndef WALL_H
#define WALL_H

#include "core/dungeon/roomedge.h"

namespace core {
namespace dungeon {

class Wall : public RoomEdge  {
  public:
    Wall();
    Wall(const Wall& other) = delete;
    virtual ~Wall();

    virtual const std::string description() const override = 0;
    virtual char displayCharacter() const override;
    virtual bool isPassage() const override;
  protected:
    Wall(Direction direction);
};
}
}

#endif // WALL_H
