#include <iostream>
#include <core/menuinterface.h>

using namespace std;

int main()
{
    core::MenuInterface m = core::MenuInterface(cout, cin);
    m.displayWelcome("Sakcham Gupta", "Dungeon Builder");
    m.run();
    return 0;
}
