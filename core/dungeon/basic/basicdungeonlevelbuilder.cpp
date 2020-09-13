#include "basicdungeonlevelbuilder.h"
#include "core/dungeon/basic/quartzchamber.h"
#include "core/dungeon/basic/rockchamber.h"
#include "core/dungeon/doorway.h"
#include "core/dungeon/common/blockeddoorway.h"
#include "core/dungeon/common/lockeddoor.h"
#include "core/dungeon/common/onewaydoor.h"
#include "core/dungeon/common/opendoorway.h"
#include "core/dungeon/basic/rockwall.h"
#include "core/items/weapon.h"
#include "core/items/consumable.h"
#include "core/creatures/monster.h"
#include "core/dungeon/basic/basicdungeonlevel.h"

namespace core::dungeon::basic {

BasicDungeonLevelBuilder::BasicDungeonLevelBuilder() : DungeonLevelBuilder() {
    prototypeItems();
    prototypeCreatures();
}

BasicDungeonLevelBuilder::~BasicDungeonLevelBuilder() {
    _level = nullptr;
}

void BasicDungeonLevelBuilder::BuildDungeonLevel(const std::string& name, const int width, const int height) {
    _level = new BasicDungeonLevel(name, width, height);
}

Room* BasicDungeonLevelBuilder::buildRoom(const int id) {
    Direction north = Direction::North;
    Direction south = Direction::South;
    Direction east = Direction::East;
    Direction west = Direction::West;
    if (_level) {
        Room* room{nullptr};
        //50% chance for each type of Room.
        if (randomInt(2) == 0) {
            room = new QuartzChamber(id);
            room->setEdge(new RockWall(north), north);
            room->setEdge(new RockWall(south), south);
            room->setEdge(new RockWall(east), east);
            room->setEdge(new RockWall(west), west);
            _level->addRoom(room);
        } else {
            room = new RockChamber(id);
            room->setEdge(new RockWall(north), north);
            room->setEdge(new RockWall(south), south);
            room->setEdge(new RockWall(east), east);
            room->setEdge(new RockWall(west), west);
            _level->addRoom(room);
        }
        return room;
    }
    return nullptr;
}

void BasicDungeonLevelBuilder::buildDoorWay(Room* origin, Room* destination, const Direction direction, const MoveConstraints constraints) {
    if (not origin or not destination) {
        return;
    }
    Doorway* originDoorway{nullptr};
    Doorway* destinationDoorway{nullptr};

    //Each case represents a bitmask, Doorways are constructed and connected accordingly.
    switch(static_cast<unsigned>(constraints)) {
    case 0:
        originDoorway = new common::OpenDoorway(direction);
        destinationDoorway = new common::OpenDoorway(originDoorway->oppositeDirection());
        originDoorway->connect(destinationDoorway);
        destinationDoorway->connect(originDoorway);
        origin->setEdge(originDoorway, direction);
        destination->setEdge(destinationDoorway, originDoorway->oppositeDirection());
        break;
    case 1:
        originDoorway = new common::OneWayDoor(direction);
        destinationDoorway = new common::OpenDoorway(originDoorway->oppositeDirection());
        originDoorway->connect(destinationDoorway);
        destinationDoorway->connect(originDoorway);
        origin->setEdge(originDoorway, direction);
        destination->setEdge(destinationDoorway, originDoorway->oppositeDirection());
        break;
    case 2:
        originDoorway = new common::OpenDoorway(direction);
        destinationDoorway = new common::OneWayDoor(originDoorway->oppositeDirection());
        originDoorway->connect(destinationDoorway);
        destinationDoorway->connect(originDoorway);
        origin->setEdge(originDoorway, direction);
        destination->setEdge(destinationDoorway, originDoorway->oppositeDirection());
        break;
    case 3:
        originDoorway = new common::BlockedDoorway(direction);
        destinationDoorway = new common::BlockedDoorway(originDoorway->oppositeDirection());
        originDoorway->connect(destinationDoorway);
        destinationDoorway->connect(originDoorway);
        origin->setEdge(originDoorway, direction);
        destination->setEdge(destinationDoorway, originDoorway->oppositeDirection());
        break;
    case 4:
        originDoorway = new common::LockedDoor(direction);
        destinationDoorway = new common::OpenDoorway(originDoorway->oppositeDirection());
        originDoorway->connect(destinationDoorway);
        destinationDoorway->connect(originDoorway);
        origin->setEdge(originDoorway, direction);
        destination->setEdge(destinationDoorway, originDoorway->oppositeDirection());
    case 6:
        originDoorway = new common::LockedDoor(direction);
        destinationDoorway = new common::OneWayDoor(originDoorway->oppositeDirection());
        originDoorway->connect(destinationDoorway);
        destinationDoorway->connect(originDoorway);
        origin->setEdge(originDoorway, direction);
        destination->setEdge(destinationDoorway, originDoorway->oppositeDirection());
        break;
    case 8:
        originDoorway = new common::OpenDoorway(direction);
        destinationDoorway = new common::LockedDoor(originDoorway->oppositeDirection());
        originDoorway->connect(destinationDoorway);
        destinationDoorway->connect(originDoorway);
        origin->setEdge(originDoorway, direction);
        destination->setEdge(destinationDoorway, originDoorway->oppositeDirection());
        break;
    case 9:
        originDoorway = new dungeon::common::OneWayDoor(direction);
        destinationDoorway = new common::LockedDoor(originDoorway->oppositeDirection());
        originDoorway->connect(destinationDoorway);
        destinationDoorway->connect(originDoorway);
        origin->setEdge(originDoorway, direction);
        destination->setEdge(destinationDoorway, originDoorway->oppositeDirection());
        break;
    case 12:
        originDoorway = new common::LockedDoor(direction);
        destinationDoorway = new common::LockedDoor(originDoorway->oppositeDirection());
        originDoorway->connect(destinationDoorway);
        destinationDoorway->connect(originDoorway);
        origin->setEdge(originDoorway, direction);
        destination->setEdge(destinationDoorway, originDoorway->oppositeDirection());
        break;
    case 5:
        Wall* originWall = new RockWall(direction);
        Wall* destinationWall = new RockWall(originWall->oppositeDirection());
        origin->setEdge(originWall, direction);
        destination->setEdge(destinationWall, originWall->oppositeDirection());
        break;
    }
    return;
}

void BasicDungeonLevelBuilder::buildEntrance(Room* room, const Direction direction) {
    common::OneWayDoor* entrance{new common::OneWayDoor(direction)};
    entrance->markAsEntrance();
    room->setEdge(entrance, direction);
}

void BasicDungeonLevelBuilder::buildExit(Room* room, const Direction direction) {
    common::OneWayDoor* exit{new common::OneWayDoor(direction)};
    exit->markAsExit();
    room->setEdge(exit, direction);
}

void BasicDungeonLevelBuilder::buildItem(Room* room) {
    //65% chance that Item is a consumable, 35% chance it is a Weapon.
    if (randomInt(100) < 65) {
        room->setItem(_consumables.at(randomInt(3))->clone());
    } else {
        room->setItem(_weapons.at(randomInt(3))->clone());
    }
}

void BasicDungeonLevelBuilder::buildCreature(Room* room) {

    room->setCreature(_creatures.at(randomInt(3))->clone());

    Doorway* north = dynamic_cast<Doorway*>(room->north());
    if (north) {
        if (north->isExit()) {
            room->creature().markAsBoss();
            return;
        }
    }
    Doorway* east  = dynamic_cast<Doorway*>(room->east());
    if (east) {
        if (east->isExit()) {
            room->creature().markAsBoss();
            return;
        }
    }
    Doorway* south = dynamic_cast<Doorway*>(room->south());
    if (south) {
        if (south->isExit()) {
            room->creature().markAsBoss();
            return;
        }
    }

    Doorway* west = dynamic_cast<Doorway*>(room->west());
    if (west) {
        if (west->isExit()) {
            room->creature().markAsBoss();
            return;
        }
    }
}

DungeonLevel* BasicDungeonLevelBuilder::getDungeonLevel() const {
    return _level;
}

void BasicDungeonLevelBuilder::prototypeItems() {
    _consumables.push_back(std::make_unique<core::items::Consumable>(core::items::Consumable("Health Potion")));
    _consumables.push_back(std::make_unique<core::items::Consumable>(core::items::Consumable("Molotov Cocktail")));
    _consumables.push_back(std::make_unique<core::items::Consumable>(core::items::Consumable("Smoke Bomb")));

    _weapons.push_back(std::make_unique<core::items::Weapon>(core::items::Weapon("Boomerang")));
    _weapons.push_back(std::make_unique<core::items::Weapon>(core::items::Weapon("Short Sword")));
    _weapons.push_back(std::make_unique<core::items::Weapon>(core::items::Weapon("Battle Axe")));
};

void BasicDungeonLevelBuilder::prototypeCreatures() {
    _creatures.push_back(std::make_unique<core::creatures::Monster>(core::creatures::Monster("Goblin")));
    _creatures.push_back(std::make_unique<core::creatures::Monster>(core::creatures::Monster("Evil Wizard")));
    _creatures.push_back(std::make_unique<core::creatures::Monster>(core::creatures::Monster("Werewolf")));
}
}
