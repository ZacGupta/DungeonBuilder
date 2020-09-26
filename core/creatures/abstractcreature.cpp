#include "abstractcreature.h"

namespace core::creatures {

AbstractCreature::AbstractCreature(std::string name) : _name{name}, _isBoss{false} {}

std::ostream& operator<<(std::ostream& out, const AbstractCreature& creature) {
    return out << creature.name();
}

const std::string AbstractCreature::name() const {
    return _name;
}

char AbstractCreature::displayCharacter() const {
    return 'M';
}

void AbstractCreature::markAsBoss() {
    _name = "Elite " + _name;
    _isBoss = true;
}

bool AbstractCreature::isBoss() const {
    return _isBoss;
}
}
