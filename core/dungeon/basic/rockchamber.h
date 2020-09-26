#ifndef ROCKCHAMBER_H
#define ROCKCHAMBER_H

#include "core/dungeon/room.h"

namespace core::dungeon::basic {

class RockChamber : public Room {
  public:
    RockChamber() = delete;
    RockChamber(const RockChamber& other) = delete;
    ~RockChamber() = default;
    RockChamber(const int id);
    //!< @brief The constructor requires the id of the room to be created.

    virtual const std::string description() const override;
    //!< @brief Returns a description of the room, including all room edges, as well as any creatures and items if present.
};
}


#endif // ROCKCHAMBER_H
