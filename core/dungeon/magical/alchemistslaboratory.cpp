#include "alchemistslaboratory.h"

namespace core::dungeon::magical {

AlchemistsLaboratory::AlchemistsLaboratory(const int id) : Room{id} {
    std::cout << "Created AlchemistsLaboratory" << std::endl;
}

AlchemistsLaboratory::~AlchemistsLaboratory() {
    std::cout << "Destoyed AlchemistsLaboratory" << std::endl;
}

const std::string AlchemistsLaboratory::description() const {
    return "An ancient laboratory with a mysterious vibe (Alchemists Laboratory)";
}

}
