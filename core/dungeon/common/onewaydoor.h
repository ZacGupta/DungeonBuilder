#ifndef ONEWAYDOOR_H
#define ONEWAYDOOR_H

#include <core/dungeon/doorway.h>

namespace core::dungeon::common {

class OneWayDoor : public Doorway {
  public:
    OneWayDoor() = delete;
    OneWayDoor(const OneWayDoor& other) = delete;
    OneWayDoor(Direction direction);
    ~OneWayDoor();

    virtual const std::string description() const override;
    virtual char displayCharacter() const override;
};
}


#endif // ONEWAYDOOR_H
