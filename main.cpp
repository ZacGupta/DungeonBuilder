#include <iostream>
#include <core/menuinterface.h>
#include <core/dungeon/basic/rockwall.h>

using namespace std;
using namespace core::dungeon::basic;
using namespace core::dungeon;

int main() {

    Direction d = Direction::East;
    RockWall wall = RockWall(d);

//    core::MenuInterface m = core::MenuInterface(cout, cin);
//    m.displayWelcome("Sakcham Gupta", "Dungeon Builder");
//    m.run();
    return 0;
}
