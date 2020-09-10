#include "monster.h"

namespace core::creatures {

Monster::Monster(std::string name) : AbstractCreature{name} {
    std::cout << "Created Monster: " << _name << std::endl;
}

Monster::~Monster() {
    std::cout << "Destroyed Monster: " << _name << std::endl;
}

void Monster::setName(std::string name) {
    _name = name;
}

std::unique_ptr<AbstractCreature> Monster::clone() {
    return std::make_unique<Monster>(*this);
}
}
