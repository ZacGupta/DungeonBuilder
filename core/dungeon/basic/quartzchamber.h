#ifndef QUARTZCHAMBER_H
#define QUARTZCHAMBER_H

#include "core/dungeon/room.h"

namespace core::dungeon::basic {

class QuartzChamber : public Room {
  public:
    QuartzChamber() = delete;
    QuartzChamber(const QuartzChamber& other) = delete;
    QuartzChamber(const int id);
    virtual ~QuartzChamber();

    virtual const std::string description() const override;
};
}


#endif // QUARTZCHAMBER_H
