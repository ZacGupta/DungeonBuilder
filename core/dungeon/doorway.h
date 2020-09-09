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

    void markAsEntrance();
    void markAsExit();
    bool isEntrance() const;
    bool isExit() const;

    const Doorway* _opposite;

  protected:

    bool _isEntrance;
    bool _isExit;

    //Protected constructor
    Doorway(Direction direction);

};
}

#endif // DOORWAY_H
