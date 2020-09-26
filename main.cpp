#include "core/menuinterface.h"
#include <iostream>

//!< @mainpage DungeonBuilder

int main() {
    core::MenuInterface menu = core::MenuInterface(std::cout, std::cin);
    menu.displayWelcome("Sakcham Gupta", "Dungeon Builder");
    menu.run();
    return 0;
}
