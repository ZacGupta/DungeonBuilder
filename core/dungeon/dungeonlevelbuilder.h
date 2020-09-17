#ifndef DUNGEONLEVELBUILDER_H
#define DUNGEONLEVELBUILDER_H

#include "core/dungeon/dungeonlevel.h"
#include "core/dungeon/room.h"
#include <string>
#include <vector>
#include <random>
#include <ctime>

namespace core::dungeon {

enum class MoveConstraints : unsigned {None = 0, OriginImpassable = 1, DestinationImpassable = 2, OriginLocked = 4, DestinationLocked = 8};
MoveConstraints operator|(const MoveConstraints& origin, const MoveConstraints& destination);
MoveConstraints operator&(const MoveConstraints& origin, const MoveConstraints& destination);

class DungeonLevelBuilder {
  public:
    DungeonLevelBuilder(const DungeonLevelBuilder& other) = delete;
    virtual ~DungeonLevelBuilder();

    virtual void BuildDungeonLevel(const std::string& name, const int width, const int height);
    virtual std::shared_ptr<Room> buildRoom(const int id);
    virtual void buildDoorWay(std::shared_ptr<Room> origin, std::shared_ptr<Room> destination, const Direction direction, const MoveConstraints constraints);
    virtual void buildEntrance(std::shared_ptr<Room> room, const Direction direction);
    virtual void buildExit(std::shared_ptr<Room> room, const Direction direction);
    virtual void buildItem(std::shared_ptr<Room> room);
    virtual void buildCreature(std::shared_ptr<Room> room);
    virtual DungeonLevel* getDungeonLevel();
  protected:
    DungeonLevelBuilder();
    virtual void prototypeItems();
    virtual void prototypeCreatures();
    int randomInt(int possibilities) const;

    DungeonLevel* _level;
    std::vector<std::unique_ptr<core::items::Item>> _weapons;
    std::vector<std::unique_ptr<core::items::Item>> _consumables;
    std::vector<std::unique_ptr<core::creatures::AbstractCreature>> _creatures;
};

}

#endif // DUNGEONLEVELBUILDER_H
