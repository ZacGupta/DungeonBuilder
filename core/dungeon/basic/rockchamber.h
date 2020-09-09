#ifndef ROCKCHAMBER_H
#define ROCKCHAMBER_H

#include <core/dungeon/room.h>

namespace core::dungeon::basic {

class RockChamber : public Room {
  public:
    RockChamber() = delete;
    RockChamber(const RockChamber& other) = delete;
    RockChamber(const int id);
    virtual ~RockChamber();

    virtual const std::string description() const override;
};
}


#endif // ROCKCHAMBER_H
