#include "consumable.h"

namespace core::items {

Consumable::Consumable(std::string name) : Item{name} {
    std::cout << "Created Consumable: " << _name << std::endl;
}

Consumable::~Consumable() {
    std::cout << "Destroyed Consumable: " << _name << std::endl;
}

std::unique_ptr<Item> Consumable::clone() {
    return std::make_unique<Consumable>(*this);
}
}
