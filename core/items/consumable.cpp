#include "consumable.h"

namespace core::items {

Consumable::Consumable(std::string name) : Item{name} {}

std::unique_ptr<Item> Consumable::clone() {
    return std::make_unique<Consumable>(*this);
}
}
