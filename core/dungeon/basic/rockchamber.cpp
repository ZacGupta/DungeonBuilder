#include "rockchamber.h"

namespace core::dungeon::basic {

RockChamber::RockChamber(const int id) : Room{id} {
    std::cout << "Created RockChamberr" << std::endl;
}

RockChamber::~RockChamber() {
    std::cout << "Destroyed RockChamber" << std::endl;
}

const std::string RockChamber::description() const {
    return "If you're lucky you might find Dwayne Johnson here (Rock Chamber)";
}

}
