#include "alchemistslaboratory.h"

namespace core::dungeon::magical {

AlchemistsLaboratory::AlchemistsLaboratory(const int id) : Room{id} {}

const std::string AlchemistsLaboratory::description() const {
    return "An ancient laboratory with a mysterious vibe (Alchemists Laboratory)";
}

}
