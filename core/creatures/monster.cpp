#include "monster.h"

namespace core::creatures {

Monster::Monster(std::string name) : AbstractCreature{name} {
    std::cout << "Created Monster: " << _name << std::endl;
}

Monster::~Monster() {
    std::cout << "Destroyed Monster: " << _name << std::endl;
}

std::unique_ptr<AbstractCreature> Monster::clone() {
    return std::make_unique<AbstractCreature>(*this);
}
}
