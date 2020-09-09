#ifndef ROCKWALL_H
#define ROCKWALL_H

#include "core/dungeon/wall.h"

namespace core {
namespace dungeon {
namespace basic {

class RockWall : Wall {
  public:
    RockWall() = delete;
    RockWall(const Wall& other) = delete;
    RockWall(Direction direction);
    ~RockWall();

    virtual const std::string description() const override;
};
}
}
}

#endif // ROCKWALL_H
