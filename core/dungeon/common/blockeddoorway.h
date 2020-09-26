#ifndef BLOCKEDDOORWAY_H
#define BLOCKEDDOORWAY_H

#include "core/dungeon/doorway.h"

namespace core::dungeon::common {

class BlockedDoorway : public Doorway {
  public:
    BlockedDoorway() = delete;
    BlockedDoorway(const BlockedDoorway& other) = delete;
    ~BlockedDoorway() = default;
    BlockedDoorway(Direction direction);
    //!< @brief The constructor requires a Direction (the location of the doorway).

    virtual const std::string description() const override;
    //!< @brief Returns a description of itself.

    virtual char displayCharacter() const override;
    //!< @brief Returns the display character for this specific type of doorway.

    virtual bool isEntrance() const override;
    //!< @brief Always returns false for this class.

    virtual bool isExit() const override;
    //!< @brief Always returns false for this class.
};
}

#endif // BLOCKEDDOORWAY_H
