#ifndef BASICDUNGEONLEVELBUILDER_H
#define BASICDUNGEONLEVELBUILDER_H

#include "core/dungeon/dungeonlevelbuilder.h"
#include "core/items/item.h"
#include "core/creatures/abstractcreature.h"
#include <map>

namespace core::dungeon::basic {

class BasicDungeonLevelBuilder : public DungeonLevelBuilder {
  public:
    BasicDungeonLevelBuilder();
    ~BasicDungeonLevelBuilder();
    BasicDungeonLevelBuilder(const BasicDungeonLevelBuilder& other) = delete;

    virtual void BuildDungeonLevel(const std::string& name, const int width, const int height) const override;
    virtual Room* buildRoom(const int id) const override;
    virtual void buildDoorWay(const Room& origin, const Room& destination) const override; //@param MoveConstraints constraints
    virtual void buildEntrance(const Room& room, const Direction direction) const override;
    virtual void buildExit(const Room& room, const Direction direction) const override;
    virtual void buildItem(const Room& room) const override;
    virtual void buildCreature(const Room& room) const override;
    virtual const DungeonLevel* getDungeonLevel() const override;
  private:
    void prototypeItems();
    void prototypeCreatures();
    std::map <int, std::unique_ptr<core::items::Item>> _items;
    std::map <int, std::unique_ptr<core::creatures::AbstractCreature>> _creatures;
};
}

#endif // BASICDUNGEONLEVELBUILDER_H
