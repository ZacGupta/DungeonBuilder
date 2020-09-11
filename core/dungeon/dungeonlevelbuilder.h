#ifndef DUNGEONLEVELBUILDER_H
#define DUNGEONLEVELBUILDER_H

#include "core/dungeon/dungeonlevel.h"
#include "core/dungeon/room.h"
#include <string>
#include <iostream> //DELETE THIS

namespace core::dungeon {

class DungeonLevelBuilder {
  public:
    DungeonLevelBuilder(const DungeonLevelBuilder& other) = default;
    virtual ~DungeonLevelBuilder();

    virtual void BuildDungeonLevel(const std::string& name, const int width, const int height) const;
    virtual Room* buildRoom(const int id) const;
    virtual void buildDoorWay(const Room& origin, const Room& destination) const; //@param MoveConstraints constraints
    virtual void buildEntrance(const Room& room, const Direction direction) const;
    virtual void buildExit(const Room& room, const Direction direction) const;
    virtual void buildItem(const Room& room) const;
    virtual void buildCreature(const Room& room) const;
    virtual const DungeonLevel* getDungeonLevel() const;
  protected:
    DungeonLevelBuilder();
};
enum class MoveConstraints : unsigned {None = 0, OriginImpassable = 1, DestinationImpassable = 2, OriginLocked = 4, DestinationLocked = 82};
}

#endif // DUNGEONLEVELBUILDER_H
