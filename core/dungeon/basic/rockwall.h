#ifndef ROCKWALL_H
#define ROCKWALL_H

#include "core/dungeon/wall.h"

namespace core::dungeon::basic {

class RockWall : public Wall {
  public:
    RockWall() = delete;
    RockWall(const RockWall& other) = delete;
    ~RockWall() = default;
    RockWall(Direction direction);
    //!< @brief The constructor requires a Direction (the location of the wall).

    virtual const std::string description() const override;
    //!< @brief Returns a description of itself.
};
}

#endif // ROCKWALL_H
