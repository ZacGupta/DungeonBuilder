#ifndef MAGICDUNGEONLEVELBUILDER_H
#define MAGICDUNGEONLEVELBUILDER_H

#include "core/dungeon/dungeonlevelbuilder.h"
#include "core/items/item.h"
#include "core/creatures/abstractcreature.h"

namespace core::dungeon::magical {

class MagicDungeonLevelBuilder : public DungeonLevelBuilder {
  public:
    MagicDungeonLevelBuilder();
    ~MagicDungeonLevelBuilder();
    MagicDungeonLevelBuilder(const MagicDungeonLevelBuilder& other) = delete;

    virtual void BuildDungeonLevel(const std::string& name, const int width, const int height) override;
    virtual Room* buildRoom(const int id) override;
    virtual void buildDoorWay(Room* origin, Room* destination, const MoveConstraints constraints) override;
    virtual void buildEntrance(Room* room, const Direction direction) override;
    virtual void buildExit(Room* room, const Direction direction) override;
    virtual void buildItem(Room* room) override;
    virtual void buildCreature(Room* room) override;
    virtual const DungeonLevel* getDungeonLevel() const override;
  private:
    void prototypeItems() override;
    void prototypeCreatures() override;
};
}


#endif // MAGICDUNGEONLEVELBUILDER_H
