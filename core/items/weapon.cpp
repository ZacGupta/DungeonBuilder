#include "weapon.h"

namespace core::items {

Weapon::Weapon(std::string name) : Item{name} {}

std::unique_ptr<Item> Weapon::clone() {
    return std::make_unique<Weapon>(*this);
}
}
