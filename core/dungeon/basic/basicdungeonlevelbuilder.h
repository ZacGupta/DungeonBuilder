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
    virtual std::shared_ptr<Room> buildRoom(int id) override;
    virtual void buildDoorWay(std::shared_ptr<Room> origin, std::shared_ptr<Room> destination, const Direction direction, const MoveConstraints constraints) override;
    virtual void buildEntrance(std::shared_ptr<Room> room, const Direction direction) override;
    virtual void buildExit(std::shared_ptr<Room> room, const Direction direction) override;
    virtual void buildItem(std::shared_ptr<Room> room) override;
    virtual void buildCreature(std::shared_ptr<Room> room) override;
    virtual DungeonLevel* getDungeonLevel() override;
  private:
    void prototypeItems() override;
    void prototypeCreatures() override;
};
}

#endif // BASICDUNGEONLEVELBUILDER_H
