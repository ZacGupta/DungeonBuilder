#include "monster.h"

namespace core::creatures {

Monster::Monster(std::string name) : AbstractCreature{name} {}

std::unique_ptr<AbstractCreature> Monster::clone() {
    return std::make_unique<Monster>(*this);
}
}
