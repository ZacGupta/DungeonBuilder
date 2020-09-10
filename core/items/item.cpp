#include "item.h"

namespace core::items {

Item::Item(std::string name) : _name{name} {
    std::cout << "Created Item: " << _name << std::endl;
}

Item::~Item() {
    std::cout << "Created Item: " << _name << std::endl;
}

std::string Item::name() {
    return _name;
}

char Item::displayCharacter() {
    return 'L';
}

}
