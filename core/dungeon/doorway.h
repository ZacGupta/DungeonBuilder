#ifndef DOORWAY_H
#define DOORWAY_H

#include "core/dungeon/roomedge.h"

namespace core::dungeon {

class Doorway : public RoomEdge {
  public:
    Doorway() = delete;
    Doorway(const Doorway& other) = delete;
    virtual ~Doorway();

    virtual const std::string description() const override = 0;
    //!< @brief Returns a description of itself.

    virtual char displayCharacter() const override = 0;
    //!< @brief Returns its own specific display character.

    virtual bool isPassage() const override;
    //!< @brief Returns true if a doorway has an opposite doorway.

    void connect(Doorway* opposite);
    //!< @brief Connects a doorway object to another object (must always be called on the opposite doorway to connect both to doorways to each other).

    virtual bool isEntrance() const;
    //!< @brief Returns true if the doorway is an entrance.

    virtual bool isExit() const;
    //!< @brief Returns true if a doorway is an exit.
  protected:
    Doorway* _opposite;
    Doorway(Direction direction);


    //Protected constructor


};
}

#endif // DOORWAY_H
