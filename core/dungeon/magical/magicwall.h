#ifndef MAGICWALL_H
#define MAGICWALL_H

#include "core/dungeon/wall.h"

namespace core::dungeon::magical {

class MagicWall : public Wall {
  public:
    MagicWall() = delete;
    MagicWall(const MagicWall& other) = delete;
    ~MagicWall();
    MagicWall(Direction direction);
    virtual const std::string description() const override;
};
}


#endif // MAGICWALL_H
