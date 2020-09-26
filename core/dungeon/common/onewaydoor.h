#ifndef ONEWAYDOOR_H
#define ONEWAYDOOR_H

#include "core/dungeon/doorway.h"

namespace core::dungeon::common {

class OneWayDoor : public Doorway {
  public:
    OneWayDoor() = delete;
    OneWayDoor(const OneWayDoor& other) = delete;
    ~OneWayDoor() = default;
    OneWayDoor(Direction direction);
    //!< @brief The constructor requires a Direction (the location of the doorway).

    virtual const std::string description() const override;
    //!< @brief Returns a description of itself.

    virtual char displayCharacter() const override;
    //!< @brief Returns the display character for this specific type of doorway,
    //!  unless the doorway is marked as an exit or entrance, then the character
    //!  returned will represent whichever one of those it is.

    virtual bool isEntrance() const override;
    //!< @brief Returns true if this doorway is marked as an entrance.

    virtual bool isExit() const override;
    //!< @brief Returns true if this doorway is marked as an exit.

    void markAsEntrance();
    //!< @brief Marks the doorway as an entrance.

    void markAsExit();
    //!< @brief Marks the doorway as an exit.
  private:
    bool _isEntrance;
    bool _isExit;
};
}


#endif // ONEWAYDOOR_H
