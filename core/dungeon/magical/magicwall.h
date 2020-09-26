#ifndef MAGICWALL_H
#define MAGICWALL_H

#include "core/dungeon/wall.h"

namespace core::dungeon::magical {

class MagicWall : public Wall {
  public:
    MagicWall() = delete;
    MagicWall(const MagicWall& other) = delete;
    ~MagicWall() = default;
    MagicWall(Direction direction);
    //!< @brief The constructor requires a Direction (the location of the wall).

    virtual const std::string description() const override;
    //!< @brief Returns a description of itself.
};
}


#endif // MAGICWALL_H
