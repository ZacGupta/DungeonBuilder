#ifndef DOORWAY_H
#define DOORWAY_H

#include <core/dungeon/roomedge.h>

namespace core::dungeon {

class Doorway : public RoomEdge {
  public:
    Doorway() = delete;
    Doorway(const Doorway& other) = delete;
    virtual ~Doorway();

    virtual const std::string description() const override = 0; //May not be neccesary to declare this again.
    virtual char displayCharacter() const override = 0; //May not be neccesary to declare this again.
    virtual bool isPassage() const override;

    void connect(const Doorway* opposite);
    const Doorway& opposite() const;

    virtual bool isEntrance() const;
    virtual bool isExit() const;

  protected:
    Doorway(Direction direction);
    const Doorway* _opposite;

    //Protected constructor


};
}

#endif // DOORWAY_H
