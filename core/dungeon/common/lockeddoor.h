#ifndef LOCKEDDOOR_H
#define LOCKEDDOOR_H

#include <core/dungeon/doorway.h>

namespace core::dungeon::common {

class LockedDoor : public Doorway {
  public:
    LockedDoor() = delete;
    LockedDoor(const LockedDoor& other) = delete;
    LockedDoor(Direction direction);
    ~LockedDoor();

    virtual const std::string description() const override;
    virtual char displayCharacter() const override;
    virtual bool isPassage() const override;
};
}


#endif // LOCKEDDOOR_H
