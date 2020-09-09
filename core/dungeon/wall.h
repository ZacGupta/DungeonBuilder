#ifndef WALL_H
#define WALL_H

#include "core/dungeon/roomedge.h"

namespace core {
namespace dungeon {

class Wall : public RoomEdge  {
  public:
    Wall() = delete;
    Wall(const Wall& other) = delete;
    Wall(Direction direction);
    virtual ~Wall();

    virtual const std::string description() const override = 0;
    virtual char displayCharacter() const override;
    virtual bool isPassage() const override;
};
}
}

#endif // WALL_H
