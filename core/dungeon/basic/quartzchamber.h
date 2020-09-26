#ifndef QUARTZCHAMBER_H
#define QUARTZCHAMBER_H

#include "core/dungeon/room.h"

namespace core::dungeon::basic {

class QuartzChamber : public Room {
  public:
    QuartzChamber() = delete;
    QuartzChamber(const QuartzChamber& other) = delete;
    ~QuartzChamber() = default;
    QuartzChamber(const int id);
    //!< @brief The constructor requires the id of the room to be created.

    virtual const std::string description() const override;
    //!< @brief Returns a description of the room, including all room edges, as well as any creatures and items if present.
};
}


#endif // QUARTZCHAMBER_H
