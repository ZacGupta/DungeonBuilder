#include "magicdungeonlevelbuilder.h"
#include "core/dungeon/magical/magicdungeonlevel.h"
#include "core/dungeon/magical/alchemistslaboratory.h"
#include "core/dungeon/magical/enchantedlibrary.h"
#include "core/items/weapon.h"
#include "core/items/consumable.h"
#include "core/creatures/monster.h"

namespace core::dungeon::magical {


MagicDungeonLevelBuilder::MagicDungeonLevelBuilder() : DungeonLevelBuilder() {
    prototypeItems();
    prototypeCreatures();
    std::cout << "Created MagicDungeonLevelBuilder" << std::endl;
}

MagicDungeonLevelBuilder::~MagicDungeonLevelBuilder() {
    std::cout << "Destroyed MagicDungeonLevelBuilder" << std::endl;
}

void MagicDungeonLevelBuilder::BuildDungeonLevel(const std::string& name, const int width, const int height) {
    _level = new MagicDungeonLevel(name, width, height);
}

Room* MagicDungeonLevelBuilder::buildRoom(const int id) {
    //50% chance for each type of Room.
    if (randomInt(2) == 0) {
        _level->addRoom(new AlchemistsLaboratory(id));
    }
    else {
        _level->addRoom(new EnchantedLibrary(id));
    }
}

void MagicDungeonLevelBuilder::buildDoorWay(Room* origin, Room* destination, const Direction direction, const MoveConstraints constraints) {

}

void MagicDungeonLevelBuilder::buildEntrance(Room* room, const Direction direction) {

}

void MagicDungeonLevelBuilder::buildExit(Room* room, const Direction direction) {

}

void MagicDungeonLevelBuilder::buildItem(Room* room) {
    //65% chance that Item is a consumable, 35% chance it is a Weapon.
    if (randomInt(100) < 65) {
        room->setItem(_consumables.at(randomInt(3))->clone());
    } else {
        room->setItem(_weapons.at(randomInt(3))->clone());
    }
}

void MagicDungeonLevelBuilder::buildCreature(Room* room) {
    room->setCreature(_creatures.at(randomInt(3))->clone());
}

DungeonLevel* MagicDungeonLevelBuilder::getDungeonLevel() const {
    return _level;
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
