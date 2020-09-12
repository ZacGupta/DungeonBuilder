#include "magicdungeonlevelbuilder.h"
#include "core/dungeon/magical/alchemistslaboratory.h"
#include "core/dungeon/magical/enchantedlibrary.h"
#include "core/items/weapon.h"
#include "core/items/consumable.h"
#include "core/creatures/monster.h"
#include <utility>

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

}

Room* MagicDungeonLevelBuilder::buildRoom(const int id) {

}

void MagicDungeonLevelBuilder::buildDoorWay(Room* origin, Room* destination, const MoveConstraints constraints) {

}

void MagicDungeonLevelBuilder::buildEntrance(Room* room, const Direction direction) {

}

void MagicDungeonLevelBuilder::buildExit(Room* room, const Direction direction) {

}

void MagicDungeonLevelBuilder::buildItem(Room* room) {

}

void MagicDungeonLevelBuilder::buildCreature(Room* room) {

}

const DungeonLevel* MagicDungeonLevelBuilder::getDungeonLevel() const {

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
