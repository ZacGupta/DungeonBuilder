#include "magicdungeonlevelbuilder.h"
#include "core/dungeon/magical/alchemistslaboratory.h"
#include "core/dungeon/magical/enchantedlibrary.h"
#include "core/items/weapon.h"
#include "core/items/consumable.h"
#include "core/creatures/monster.h"
#include <utility>

namespace core::dungeon::magical {


MagicDungeonLevelBuilder::MagicDungeonLevelBuilder() {
    prototypeItems();
    prototypeCreatures();
}

void MagicDungeonLevelBuilder::BuildDungeonLevel(const std::string& name, const int width, const int height) const {
}

Room* MagicDungeonLevelBuilder::buildRoom(const int id) const {
    return new EnchantedLibrary(1);

}

void MagicDungeonLevelBuilder::buildDoorWay(const Room& origin, const Room& destination) const {

}

void MagicDungeonLevelBuilder::buildEntrance(const Room& room, const Direction direction) const {

}

void MagicDungeonLevelBuilder::buildExit(const Room& room, const Direction direction) const {

}

void MagicDungeonLevelBuilder::buildItem(const Room& room) const {

}

void MagicDungeonLevelBuilder::buildCreature(const Room& room) const {

}

const DungeonLevel MagicDungeonLevelBuilder::getDungeonLevel() const {

}

void MagicDungeonLevelBuilder::prototypeItems() {
    _items.insert(std::pair<int, std::unique_ptr<core::items::Consumable>>(0, std::make_unique<core::items::Consumable>(core::items::Consumable("Health Potion"))));
    _items.insert(std::pair<int, std::unique_ptr<core::items::Consumable>>(1, std::make_unique<core::items::Consumable>(core::items::Consumable("Molotov Cocktail"))));
    _items.insert(std::pair<int, std::unique_ptr<core::items::Consumable>>(2, std::make_unique<core::items::Consumable>(core::items::Consumable("Resistance Potion"))));
    _items.insert(std::pair<int, std::unique_ptr<core::items::Weapon>>(3, std::make_unique<core::items::Weapon>(core::items::Weapon("Boomerang"))));
    _items.insert(std::pair<int, std::unique_ptr<core::items::Weapon>>(4, std::make_unique<core::items::Weapon>(core::items::Weapon("Wizard's Staff"))));
    _items.insert(std::pair<int, std::unique_ptr<core::items::Weapon>>(5, std::make_unique<core::items::Weapon>(core::items::Weapon("Magic Wand"))));
}

void MagicDungeonLevelBuilder::prototypeCreatures() {
    _creatures.insert(std::pair<int, std::unique_ptr<core::creatures::Monster>>(0, std::make_unique<core::creatures::Monster>(core::creatures::Monster("Goblin"))));
    _creatures.insert(std::pair<int, std::unique_ptr<core::creatures::Monster>>(1, std::make_unique<core::creatures::Monster>(core::creatures::Monster("Evil Wizard"))));
    _creatures.insert(std::pair<int, std::unique_ptr<core::creatures::Monster>>(2, std::make_unique<core::creatures::Monster>(core::creatures::Monster("Dragon"))));
}

}
