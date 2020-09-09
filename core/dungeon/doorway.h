#ifndef DOORWAY_H
#define DOORWAY_H

#include <core/dungeon/roomedge.h>

namespace core::dungeon {

class Doorway : public RoomEdge {
  public:
    Doorway();
    Doorway(const Doorway& other) = delete;
    virtual ~Doorway();

    friend std::ostream& operator<<(std::ostream& out, const Doorway& doorway);  //operator overload (<<)

    virtual const std::string description() const override = 0; //May not be neccesary to declare this again.
    virtual char displayCharacter() const override = 0; //May not be neccesary to declare this again.
    virtual bool isPassage() const override = 0; //May not be neccesary to declare this again.

    void connect(const Doorway* opposite);
    bool isEntrance() const;
    bool isExit() const;

  protected:
    Doorway* opposite;
    //Protected constructor
    Doorway(Direction direction);

};
}

#endif // DOORWAY_H
