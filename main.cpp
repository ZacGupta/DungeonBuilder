#include <iostream>
#include <core/menuinterface.h>
#include <core/dungeon/basic/rockwall.h>
#include <core/dungeon/magical/magicwall.h>
#include <core/dungeon/common/opendoorway.h>
#include <core/dungeon/common/onewaydoor.h>
#include <core/dungeon/common/lockeddoor.h>
#include <core/dungeon/common/blockeddoorway.h>
#include <core/dungeon/basic/rockchamber.h>
#include <core/creatures/monster.h>
#include <core/items/weapon.h>
#include <core/dungeon/basic/basicdungeonlevelbuilder.h>
#include <core/dungeon/magical/magicdungeonlevelbuilder.h>
#include <core/dungeon/basic/basicdungeonlevel.h>
#include <core/game.h>
#include <set>
#include <memory>
#include <map>
#include <vector>

using namespace std;
using namespace core;
using namespace core::dungeon;
using namespace core::dungeon::basic;
using namespace core::dungeon::magical;
using namespace core::dungeon::common;
using namespace core::items;
using namespace core::creatures;

int main() {

//    MoveConstraints mc = MoveConstraints::DestinationLocked&MoveConstraints::OriginLocked;

//    static_cast<unsigned>(mc);

//    cout << mc << endl;

//    RockChamber r = RockChamber(1);

//    OneWayDoor* d1 = new OneWayDoor(Direction::North);
//    RoomEdge* d2 = new BlockedDoorway(Direction::South);
//    RoomEdge* d3 = new LockedDoor(Direction::East);
//    RoomEdge* d4 = new OpenDoorway(Direction::West);
//    unique_ptr<AbstractCreature> m {new Monster("Monster")};
//    unique_ptr<Item> w {new Weapon("Weapon")};


//    m->markAsBoss();
//    r.setCreature(move(m));
//    r.setItem(move(w));
//    d1->markAsEntrance();
//    r.setNorth(d1);
//    r.setSouth(d2);
//    r.setEast(d3);
//    r.setWest(d4);

//    cout << r.display().at(0) << endl;
//    cout << r.display().at(1) << endl;
//    cout << r.display().at(2) << endl;
//    cout << r.display().at(3) << endl;
//    cout << r.display().at(4) << endl;

    Game* game = game->instance();
    unique_ptr<BasicDungeonLevelBuilder> dlb{new BasicDungeonLevelBuilder()};
    unique_ptr<MagicDungeonLevelBuilder> dlb2{new MagicDungeonLevelBuilder()};
    game->setDungeonType(move(dlb2));
    game->createRandomLevel("Random Dungeon", 4, 4);
//    game->createExampleLevel();

    game->displayLevel(cout);

//    for (string line : v) {
//        cout << line << endl;
//    }

//    game->setDungeonType(move(dlb2));

//    unique_ptr<BasicDungeonLevelBuilder> dlb{new BasicDungeonLevelBuilder()};
//    std::vector <dungeon::Room*> rooms;
//    dlb->BuildDungeonLevel("Example", 1, 2);
//    rooms.push_back(dlb->buildRoom(1));
//    rooms.push_back(dlb->bu1ildRoom(2));
//    dlb->buildDoorWay(rooms.at(0), rooms.at(1), dungeon::Direction::East, dungeon::MoveConstraints::DestinationImpassable);


//    game->createRandomLevel("Level", 1, 1);

//    //Initialise Game
//    Game* game = game->instance();

//    Room* room1 = new RockChamber(1);
//    Room* room2 = new RockChamber(2);
//    Room* room3 = new RockChamber(3);
//    Room* room4 = new RockChamber(4);
//    Room* room5 = new RockChamber(5);
//    Room* room6 = new RockChamber(6);

//    BasicDungeonLevel bdl = BasicDungeonLevel("Test Dungeon", 3, 2);
//    bdl.addRoom(room1);
//    bdl.addRoom(room2);
//    bdl.addRoom(room3);
//    bdl.addRoom(room4);
//    bdl.addRoom(room5);
//    bdl.addRoom(room6);

//    Room* rr = bdl.retrieveRoom(3);

//    if (rr) {
//        cout << rr->id() << endl;
//        cout << rr->description() << endl;
//    }

//    //Do this when finished with the retreived Room
//    rr = nullptr;

//    //UNIQUE POINTER TESTING
//    Game* game = game->instance();
//    unique_ptr<DungeonLevelBuilder> dlb{new BasicDungeonLevelBuilder()};
//    unique_ptr<MagicDungeonLevelBuilder> dlb2{new MagicDungeonLevelBuilder()};
//    unique_ptr<DungeonLevelBuilder> dlb3{new BasicDungeonLevelBuilder()};

//    //Main will send a unique pointer to Game, which Game will take ownership of via std::move(), which also deletes the previous builder.
//    //The final Builder will only be deleted AFTER main ends because Game is static, and Game itself won't be deleted until Main ends.
//    game->setDungeonType(std::move(dlb));
//    game->setDungeonType(std::move(dlb2));
//    game->setDungeonType(std::move(dlb3));
//    //END UNIQUE POINTER TESTING

//    //SHARED POINTER TESTING
//    //A new dungeon
//    shared_ptr<BasicDungeonLevelBuilder> dlb{new BasicDungeonLevelBuilder};
//    //Initialise Game
//    Game* game = game->instance();
//    //Set Dungeonm
//    game->setDungeonType(dlb);

//    //There a pointer to the dungeon in main AND game now.
//    cout << "Dungeon Pointer count: " << dlb.use_count() << endl;

//    //A new dungeon needs to be built
//    shared_ptr<BasicDungeonLevelBuilder> dlb2{new BasicDungeonLevelBuilder};

//    //Game will delete it's copy of the previous shared pointer when setDungeonType() is called, THEN create a copy of the new dungeon.
//    game->setDungeonType(dlb2);

//    //When setting a new dungeon, main must delete it's old copy too.
//    cout << "Reset Dungeon" << endl;
//    dlb.reset();
//    cout << "Now there's a new dungeon" << endl;
//    cout << "Old dungeon Pointer count: " << dlb.use_count() << endl;
//    cout << "New dungeon Pointer count: " << dlb2.use_count() << endl;
//    //END SHARED POINTER TESTING


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
