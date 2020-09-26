#ifndef MAGICDUNGEONLEVELBUILDER_H
#define MAGICDUNGEONLEVELBUILDER_H

#include "core/dungeon/dungeonlevelbuilder.h"
#include "core/items/item.h"
#include "core/creatures/abstractcreature.h"

namespace core::dungeon::magical {

class MagicDungeonLevelBuilder : public DungeonLevelBuilder {
  public:
    MagicDungeonLevelBuilder(const MagicDungeonLevelBuilder& other) = delete;
    ~MagicDungeonLevelBuilder() = default;
    MagicDungeonLevelBuilder();

    virtual void buildDungeonLevel(const std::string& name, const int width, const int height) override;
    //!< @brief Builds a new DungeonLevel object.

    virtual std::shared_ptr<Room> buildRoom(int id) override;
    //!< @brief Builds a room object with the specified id into the DungeonLevel object.

    virtual void buildDoorWay(std::shared_ptr<Room> origin, std::shared_ptr<Room> destination, const Direction direction, const MoveConstraints constraints) override;
    //!< @brief Builds a doorway in the origin and destination rooms based on the specified constraints.

    virtual void buildEntrance(std::shared_ptr<Room> room, const Direction direction) override;
    //!< @brief Builds an entrance (OneWayDoor object) inside the specified room at the specified direction.

    virtual void buildExit(std::shared_ptr<Room> room, const Direction direction) override;
    //!< @brief Builds an exit (OneWayDoor object) inside the specified room at the specified direction.

    virtual void buildItem(std::shared_ptr<Room> room) override;
    //!< @brief Builds an item inside the specified room.

    virtual void buildCreature(std::shared_ptr<Room> room) override;
    //!< @brief Builds a creature inside the specified Room.

    virtual DungeonLevel* getDungeonLevel() override;
    //!< @brief Transfers ownership of the DungeonLevel object created by using buildDungeonLevel(),
    //!  If no DungeonLevel object was created before calling this method, a nullptr is returned.
  private:
    virtual void prototypeItems() override;
    virtual void prototypeCreatures() override;
};
}

#endif // MAGICDUNGEONLEVELBUILDER_H
