#ifndef DUNGEONLEVELBUILDER_H
#define DUNGEONLEVELBUILDER_H

#include "core/dungeon/dungeonlevel.h"
#include "core/dungeon/room.h"
#include <string>
#include <vector>
#include <iostream> //DELETE THIS

namespace core::dungeon {

enum class MoveConstraints : unsigned {None = 0, OriginImpassable = 1, DestinationImpassable = 2, OriginLocked = 4, DestinationLocked = 8};

class DungeonLevelBuilder {
  public:
    DungeonLevelBuilder(const DungeonLevelBuilder& other) = delete;
    virtual ~DungeonLevelBuilder();

    virtual void BuildDungeonLevel(const std::string& name, const int width, const int height);
    virtual Room* buildRoom(const int id);
    virtual void buildDoorWay(Room* origin, Room* destination, const MoveConstraints constraints);
    virtual void buildEntrance(Room* room, const Direction direction);
    virtual void buildExit(Room* room, const Direction direction);
    virtual void buildItem(Room* room);
    virtual void buildCreature(Room* room);
    virtual const DungeonLevel* getDungeonLevel() const;
  protected:
    DungeonLevelBuilder();
    virtual void prototypeItems();
    virtual void prototypeCreatures();

    DungeonLevel* _level;
    std::vector<std::unique_ptr<core::items::Item>> _weapons;
    std::vector<std::unique_ptr<core::items::Item>> _consumables;
    std::vector<std::unique_ptr<core::creatures::AbstractCreature>> _creatures;
};

}

#endif // DUNGEONLEVELBUILDER_H
