#ifndef ROCKWALL_H
#define ROCKWALL_H

#include "core/dungeon/wall.h"

namespace core::dungeon::basic {

class RockWall : public Wall {
  public:
    RockWall() = delete;
    RockWall(const RockWall& other) = delete;
    RockWall(Direction direction);
    ~RockWall() = default;

    virtual const std::string description() const override;
};
}

#endif // ROCKWALL_H
