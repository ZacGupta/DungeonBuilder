#include "magicdungeonlevelbuilder.h"
#include "core/dungeon/magical/magicdungeonlevel.h"
#include "core/dungeon/magical/alchemistslaboratory.h"
#include "core/dungeon/magical/enchantedlibrary.h"
#include "core/dungeon/magical/magicwall.h"
#include "core/dungeon/doorway.h"
#include "core/dungeon/common/blockeddoorway.h"
#include "core/dungeon/common/lockeddoor.h"
#include "core/dungeon/common/onewaydoor.h"
#include "core/dungeon/common/opendoorway.h"
#include "core/items/weapon.h"
#include "core/items/consumable.h"
#include "core/creatures/monster.h"

namespace core::dungeon::magical {

MagicDungeonLevelBuilder::MagicDungeonLevelBuilder() : DungeonLevelBuilder() {
    prototypeItems();
    prototypeCreatures();
}

void MagicDungeonLevelBuilder::buildDungeonLevel(const std::string& name, const int width, const int height) {
    _level = new MagicDungeonLevel(name, width, height);
}

std::shared_ptr<Room> MagicDungeonLevelBuilder::buildRoom(const int id) {
    Direction north{Direction::North};
    Direction south{Direction::South};
    Direction east{Direction::East};
    Direction west{Direction::West};
    if (_level) {
        //50% chance for each type of Room.
        if (randomInt(2) == 0) {
            std::shared_ptr<EnchantedLibrary> room{new EnchantedLibrary(id)};
            room->setEdge(new MagicWall(north), north);
            room->setEdge(new MagicWall(south), south);
            room->setEdge(new MagicWall(east), east);
            room->setEdge(new MagicWall(west), west);
            _level->addRoom(room);
            return room;
        } else {
            std::shared_ptr<AlchemistsLaboratory> room{new AlchemistsLaboratory(id)};
            room->setEdge(new MagicWall(north), north);
            room->setEdge(new MagicWall(south), south);
            room->setEdge(new MagicWall(east), east);
            room->setEdge(new MagicWall(west), west);
            _level->addRoom(room);
            return room;
        }
    }
    return nullptr;
}

void MagicDungeonLevelBuilder::buildDoorWay(std::shared_ptr<Room> origin, std::shared_ptr<Room> destination, const Direction direction, const MoveConstraints constraints) {
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
    }
}

void MagicDungeonLevelBuilder::buildEntrance(std::shared_ptr<Room> room, const Direction direction) {
    common::OneWayDoor* entrance{new common::OneWayDoor(direction)};
    entrance->markAsEntrance();
    room->setEdge(entrance, direction);
}

void MagicDungeonLevelBuilder::buildExit(std::shared_ptr<Room> room, const Direction direction) {
    common::OneWayDoor* exit{new common::OneWayDoor(direction)};
    exit->markAsExit();
    room->setEdge(exit, direction);
}

void MagicDungeonLevelBuilder::buildItem(std::shared_ptr<Room> room) {
    //65% chance that Item is a consumable, 35% chance it is a Weapon.
    if (randomInt(100) < 65) {
        room->setItem(_consumables.at(randomInt(3))->clone());
    } else {
        room->setItem(_weapons.at(randomInt(3))->clone());
    }
}

void MagicDungeonLevelBuilder::buildCreature(std::shared_ptr<Room> room) {
    room->setCreature(_creatures.at(randomInt(3))->clone());

    //If any of the room edges are exits, then the creature will be marked as a boss.
    Doorway* north{dynamic_cast<Doorway*>(room->north())};
    if (north) {
        if (north->isExit()) {
            room->creature().markAsBoss();
            return;
        }
    }
    Doorway* east{dynamic_cast<Doorway*>(room->east())};
    if (east) {
        if (east->isExit()) {
            room->creature().markAsBoss();
            return;
        }
    }
    Doorway* south{dynamic_cast<Doorway*>(room->south())};
    if (south) {
        if (south->isExit()) {
            room->creature().markAsBoss();
            return;
        }
    }

    Doorway* west{dynamic_cast<Doorway*>(room->west())};
    if (west) {
        if (west->isExit()) {
            room->creature().markAsBoss();
        }
    }
}

DungeonLevel* MagicDungeonLevelBuilder::getDungeonLevel() {
    DungeonLevel* temp{_level};
    _level = nullptr;
    return temp;
}

void MagicDungeonLevelBuilder::prototypeItems() {
    _consumables.push_back(std::make_unique<core::items::Consumable>(core::items::Consumable("Health Potion")));
    _consumables.push_back(std::make_unique<core::items::Consumable>(core::items::Consumable("Molotov Cocktail")));
    _consumables.push_back(std::make_unique<core::items::Consumable>(core::items::Consumable("Resistance Potion")));

    _weapons.push_back(std::make_unique<core::items::Weapon>(core::items::Weapon("Boomerang")));
    _weapons.push_back(std::make_unique<core::items::Weapon>(core::items::Weapon("Wizard's Staff")));
    _weapons.push_back(std::make_unique<core::items::Weapon>(core::items::Weapon("Magic Wand")));
};

void MagicDungeonLevelBuilder::prototypeCreatures() {
    _creatures.push_back(std::make_unique<core::creatures::Monster>(core::creatures::Monster("Goblin")));
    _creatures.push_back(std::make_unique<core::creatures::Monster>(core::creatures::Monster("Evil Wizard")));
    _creatures.push_back(std::make_unique<core::creatures::Monster>(core::creatures::Monster("Dragon")));
}
}
