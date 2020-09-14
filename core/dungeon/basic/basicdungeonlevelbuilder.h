#ifndef BASICDUNGEONLEVELBUILDER_H
#define BASICDUNGEONLEVELBUILDER_H

#include "core/dungeon/dungeonlevelbuilder.h"
#include "core/items/item.h"
#include "core/creatures/abstractcreature.h"

namespace core::dungeon::basic {

class BasicDungeonLevelBuilder : public DungeonLevelBuilder {
  public:
    BasicDungeonLevelBuilder();
    ~BasicDungeonLevelBuilder();
    BasicDungeonLevelBuilder(const BasicDungeonLevelBuilder& other) = delete;

    virtual void BuildDungeonLevel(const std::string& name, const int width, const int height) override;
    virtual Room* buildRoom(int id) override;
    virtual void buildDoorWay(Room* origin, Room* destination, const Direction direction, const MoveConstraints constraints) override;
    virtual void buildEntrance(Room* room, const Direction direction) override;
    virtual void buildExit(Room* room, const Direction direction) override;
    virtual void buildItem(Room* room) override;
    virtual void buildCreature(Room* room) override;
    virtual DungeonLevel* getDungeonLevel() override;
  private:
    void prototypeItems() override;
    void prototypeCreatures() override;
};
}

#endif // BASICDUNGEONLEVELBUILDER_H
