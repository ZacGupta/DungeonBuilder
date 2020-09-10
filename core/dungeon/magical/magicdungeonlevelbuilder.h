#ifndef MAGICDUNGEONLEVELBUILDER_H
#define MAGICDUNGEONLEVELBUILDER_H

#include <core/dungeon/dungeonlevelbuilder.h>

namespace core::dungeon::magical {

class MagicDungeonLevelBuilder : DungeonLevelBuilder {
  public:
    MagicDungeonLevelBuilder(const MagicDungeonLevelBuilder& other) = delete;

    MagicDungeonLevelBuilder();
    ~MagicDungeonLevelBuilder();

    virtual void BuildDungeonLevel(const std::string& name, const int width, const int height) const override;
    virtual Room* buildRoom(const int id) const override;
    virtual void buildDoorWay(const Room& origin, const Room& destination) const override; //@param MoveConstraints constraints
    virtual void buildEntrance(const Room& room, const Direction direction) const override;
    virtual void buildExit(const Room& room, const Direction direction) const override;
    virtual void buildItem(const Room& room) const override;
    virtual void buildCreature(const Room& room) const override;
    virtual const DungeonLevel getDungeonLevel() const override;
};
}


#endif // MAGICDUNGEONLEVELBUILDER_H
