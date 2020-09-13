#ifndef BLOCKEDDOORWAY_H
#define BLOCKEDDOORWAY_H

#include "core/dungeon/doorway.h"

namespace core::dungeon::common {

class BlockedDoorway : public Doorway {
  public:
    BlockedDoorway() = delete;
    BlockedDoorway(const BlockedDoorway& other) = delete;
    BlockedDoorway(Direction direction);
    ~BlockedDoorway() = default;

    virtual const std::string description() const override;
    virtual char displayCharacter() const override;
    virtual bool isEntrance() const override;
    virtual bool isExit() const override;
};
}

#endif // BLOCKEDDOORWAY_H
