#include "basicdungeonlevelbuilder.h"
#include "core/dungeon/basic/quartzchamber.h"
#include "core/dungeon/basic/rockchamber.h"
#include "core/items/weapon.h"
#include "core/items/consumable.h"
#include "core/creatures/monster.h"
#include "core/dungeon/basic/basicdungeonlevel.h"
#include <utility>

namespace core::dungeon::basic {

BasicDungeonLevelBuilder::BasicDungeonLevelBuilder() : DungeonLevelBuilder() {
    prototypeItems();
    prototypeCreatures();
    std::cout << "Created BasicDungeonLevelBuilder" << std::endl;
}

BasicDungeonLevelBuilder::~BasicDungeonLevelBuilder() {
    std::cout << "Destroyed BasicDungeonLevelBuilder" << std::endl;
}

void BasicDungeonLevelBuilder::BuildDungeonLevel(const std::string& name, const int width, const int height) {
    _level = new BasicDungeonLevel(name, width, height);
}

Room* BasicDungeonLevelBuilder::buildRoom(const int id) {
    //50% chance for each type of Room.
    if (randomInt(2) == 0) {
        _level->addRoom(new QuartzChamber(id));
    }
    else {
        _level->addRoom(new RockChamber(id));
    }
}

void BasicDungeonLevelBuilder::buildDoorWay(Room* origin, Room* destination, const MoveConstraints constraints) {

}

void BasicDungeonLevelBuilder::buildEntrance(Room* room, const Direction direction) {

}

void BasicDungeonLevelBuilder::buildExit(Room* room, const Direction direction) {

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
}

const DungeonLevel* BasicDungeonLevelBuilder::getDungeonLevel() const {

}

void BasicDungeonLevelBuilder::prototypeItems() {
    _consumables.push_back(std::make_unique<core::items::Consumable>(core::items::Consumable("Health Potion")));
    _consumables.push_back(std::make_unique<core::items::Consumable>(core::items::Consumable("Molotov Cocktail")));
    _consumables.push_back(std::make_unique<core::items::Consumable>(core::items::Consumable("Resistance Potion")));

    _weapons.push_back(std::make_unique<core::items::Weapon>(core::items::Weapon("Boomerang")));
    _weapons.push_back(std::make_unique<core::items::Weapon>(core::items::Weapon("Wizard's Staff")));
    _weapons.push_back(std::make_unique<core::items::Weapon>(core::items::Weapon("Basic Wand")));
};

void BasicDungeonLevelBuilder::prototypeCreatures() {
    _creatures.push_back(std::make_unique<core::creatures::Monster>(core::creatures::Monster("Goblin")));
    _creatures.push_back(std::make_unique<core::creatures::Monster>(core::creatures::Monster("Evil Wizard")));
    _creatures.push_back(std::make_unique<core::creatures::Monster>(core::creatures::Monster("Dragon")));
}

int BasicDungeonLevelBuilder::randomInt(double possibilities) {
    std::uniform_real_distribution<double> realDistribution{0, possibilities};
    std::mt19937 randomGenerator{uint32_t(time(nullptr))};
    return realDistribution(randomGenerator);
}

}
