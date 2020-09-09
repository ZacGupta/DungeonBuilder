#include <iostream>
#include <core/menuinterface.h>
#include <core/dungeon/basic/rockwall.h>
#include <core/dungeon/magical/magicwall.h>

using namespace std;
using namespace core::dungeon;
using namespace core::dungeon::basic;
using namespace core::dungeon::magical;


int main() {

    Direction dNorth = Direction::North;
    Direction dEast = Direction::East;

    RockWall wall = RockWall(dNorth);
    cout << wall.description() << wall.isPassage() <<  wall.displayCharacter() << std::endl;
    MagicWall wall2 = MagicWall(dEast);
    cout << wall2.description() << wall2.isPassage() << wall2.displayCharacter() << std::endl;

//    core::MenuInterface m = core::MenuInterface(cout, cin);
//    m.displayWelcome("Sakcham Gupta", "Dungeon Builder");
//    m.run();
    return 0;
}
