#include "abstractcreature.h"

namespace core::creatures {

AbstractCreature::AbstractCreature(std::string name) : _name{name}, _isBoss{false} {
    std::cout << "Created AbstractCreature: " << _name << std::endl;
}

AbstractCreature::~AbstractCreature() {
    std::cout << "Destroyed AbstractCreature: " << _name << std::endl;
}

std::string AbstractCreature::name() {
    return _name;
}

char AbstractCreature::displayCharacter() {
    return 'M';
}

void AbstractCreature::markAsBoss() {
    _isBoss = true;
}

bool AbstractCreature::isBoss() {
    return _isBoss;
}

}
