#include <iostream>
#include <core/menuinterface.h>
#include <core/dungeon/basic/rockwall.h>
#include <core/dungeon/magical/magicwall.h>
#include <core/dungeon/common/opendoorway.h>

using namespace std;
using namespace core::dungeon;
using namespace core::dungeon::basic;
using namespace core::dungeon::magical;
using namespace core::dungeon::common;


int main() {

    OpenDoorway d1 = OpenDoorway(Direction::North);
    OpenDoorway d2 = OpenDoorway(Direction::South);


    cout << "End of main" << endl;


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
