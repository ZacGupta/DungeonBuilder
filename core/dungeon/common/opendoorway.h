#ifndef OPENDOORWAY_H
#define OPENDOORWAY_H

#include "core/dungeon/doorway.h"

namespace core::dungeon::common {

class OpenDoorway : public Doorway {
  public:
    OpenDoorway() = delete;
    OpenDoorway(const OpenDoorway& other) = delete;
    OpenDoorway(Direction direction);
    ~OpenDoorway();

    virtual const std::string description() const override;
    virtual char displayCharacter() const override;
};
}


#endif // OPENDOORWAY_H
