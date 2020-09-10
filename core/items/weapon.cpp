#include "weapon.h"

namespace core::items {

Weapon::Weapon(std::string name) : Item{name} {
    std::cout << "Created Weapon: " << _name << std::endl;
}

Weapon::~Weapon() {
    std::cout << "Created Weapon: " << _name << std::endl;
}

std::unique_ptr<Item> Weapon::clone() {
    return std::make_unique<Weapon>(*this);
}
}
