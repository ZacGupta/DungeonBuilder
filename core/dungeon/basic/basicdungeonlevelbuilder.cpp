#include "basicdungeonlevelbuilder.h"
#include "core/dungeon/basic/quartzchamber.h"
#include "core/dungeon/basic/rockchamber.h"
#include "core/items/weapon.h"
#include "core/items/consumable.h"
#include "core/creatures/monster.h"
#include "core/dungeon/basic/basicdungeonlevel.h"
#include <utility>

namespace core::dungeon::basic {

BasicDungeonLevelBuilder::BasicDungeonLevelBuilder() {
    std::cout << "Created BasicDungeonLevelBuilder" << std::endl;
    prototypeItems();
    prototypeCreatures();
}

BasicDungeonLevelBuilder::~BasicDungeonLevelBuilder() {
    std::cout << "Destroyed BasicDungeonLevelBuilder" << std::endl;
}

void BasicDungeonLevelBuilder::BuildDungeonLevel(const std::string& name, const int width, const int height) const {
}

Room* BasicDungeonLevelBuilder::buildRoom(const int id) const {
    return new QuartzChamber(1);
}

void BasicDungeonLevelBuilder::buildDoorWay(const Room& origin, const Room& destination) const {
}

void BasicDungeonLevelBuilder::buildEntrance(const Room& room, const Direction direction) const {

}

void BasicDungeonLevelBuilder::buildExit(const Room& room, const Direction direction) const {

}

void BasicDungeonLevelBuilder::buildItem(const Room& room) const {

}

void BasicDungeonLevelBuilder::buildCreature(const Room& room) const {

}

const DungeonLevel* BasicDungeonLevelBuilder::getDungeonLevel() const {
    return new BasicDungeonLevel{"name", 1,1};
}

void BasicDungeonLevelBuilder::prototypeItems() {
    _items.insert(std::pair<int, std::unique_ptr<core::items::Consumable>>(0, std::make_unique<core::items::Consumable>(core::items::Consumable("Health Potion"))));
    _items.insert(std::pair<int, std::unique_ptr<core::items::Consumable>>(1, std::make_unique<core::items::Consumable>(core::items::Consumable("Molotov Cocktail"))));
    _items.insert(std::pair<int, std::unique_ptr<core::items::Consumable>>(2, std::make_unique<core::items::Consumable>(core::items::Consumable("Smoke Bomb"))));
    _items.insert(std::pair<int, std::unique_ptr<core::items::Weapon>>(3, std::make_unique<core::items::Weapon>(core::items::Weapon("Boomerang"))));
    _items.insert(std::pair<int, std::unique_ptr<core::items::Weapon>>(4, std::make_unique<core::items::Weapon>(core::items::Weapon("short Sword"))));
    _items.insert(std::pair<int, std::unique_ptr<core::items::Weapon>>(5, std::make_unique<core::items::Weapon>(core::items::Weapon("Battle Axe"))));
}

void BasicDungeonLevelBuilder::prototypeCreatures() {
    _creatures.insert(std::pair<int, std::unique_ptr<core::creatures::Monster>>(0, std::make_unique<core::creatures::Monster>(core::creatures::Monster("Goblin"))));
    _creatures.insert(std::pair<int, std::unique_ptr<core::creatures::Monster>>(1, std::make_unique<core::creatures::Monster>(core::creatures::Monster("Werewolf"))));
    _creatures.insert(std::pair<int, std::unique_ptr<core::creatures::Monster>>(2, std::make_unique<core::creatures::Monster>(core::creatures::Monster("Evil Wizard"))));
}

}
