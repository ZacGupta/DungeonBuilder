#include <iostream>
#include <core/menuinterface.h>
#include <core/dungeon/basic/rockwall.h>
#include <core/dungeon/magical/magicwall.h>
#include <core/dungeon/common/opendoorway.h>
#include <core/dungeon/common/onewaydoor.h>
#include <core/dungeon/basic/rockchamber.h>
#include <core/creatures/monster.h>
#include <core/items/weapon.h>
#include <core/dungeon/basic/basicdungeonlevelbuilder.h>
#include <core/game.h>
#include <set>
#include <memory>
#include <map>

using namespace std;
using namespace core;
using namespace core::dungeon;
using namespace core::dungeon::basic;
using namespace core::dungeon::magical;
using namespace core::dungeon::common;
using namespace core::items;
using namespace core::creatures;

int main() {

    BasicDungeonLevelBuilder* dlb = new BasicDungeonLevelBuilder;

    BasicDungeonLevelBuilder* dlb2 = new BasicDungeonLevelBuilder;


    //shared_ptr<BasicDungeonLevelBuilder> dlb = make_shared<BasicDungeonLevelBuilder>(new BasicDungeonLevelBuilder);
    Game* game = game->instance();
    game->setDungeonType(dlb);

    cout << "Reset Dungeon";

    game->setDungeonType(dlb);




//    BasicDungeonLevelBuilder dlv{BasicDungeonLevelBuilder()};

//    cout << dlv._items.at(1)->name() << endl;




//    RockChamber r = RockChamber(1);

//    OneWayDoor* d1 = new OneWayDoor(Direction::North);
//    OneWayDoor* d2 = new OneWayDoor(Direction::South);
//    OneWayDoor* d3 = new OneWayDoor(Direction::East);
//    OneWayDoor* d4 = new OneWayDoor(Direction::West);

//    r.setNorth(d1);
//    r.setSouth(d2);
//    r.setEast(d3);
//    r.setWest(d4);

//    map <int, unique_ptr<Item>> items;

//   items.insert(std::pair<int,unique_ptr<Weapon>>(1, make_unique<Weapon>(Weapon("sword"))));

//    d1->connect(d2);
//    d2->connect(d1);

//    cout << r.north().isPassage() << endl;
//    cout << r.south().isPassage() << endl;
//    cout << r.east().isPassage() << endl;
//    cout << r.west().isPassage() << endl;

//    cout << "d1: " << &d1 << endl;
//    cout << "d2: " << &d2 << endl;
//    cout << "d1.opposite: "<< &d1._opposite << endl;
//    cout << d2->isExit() << endl;
//    cout << d2->isExit() << endl;
//    cout << &d1 << endl;

//    cout << "Delete d1.opposite" << endl;
//    delete d1._opposite;

//    cout << "d2: " << &d2 << endl;
//    cout << "d1.opposite: " << &d1._opposite << endl;

//    cout << "End of main" << endl;

//    Direction dNorth = Direction::North;
//    Direction dEast = Direction::East;

//    RockWall wall = RockWall(dNorth);
//    cout << wall.description() << wall.isPassage() <<  wall.displayCharacter() << std::endl;
//    MagicWall wall2 = MagicWall(dEast);
//    cout << wall2.description() << wall2.isPassage() << wall2.displayCharacter() << std::endl;

//    core::MenuInterface m = core::MenuInterface(cout, cin);
//    m.displayWelcome("Sakcham Gupta", "Dungeon Builder");
//    m.run();
    return 0;
}
