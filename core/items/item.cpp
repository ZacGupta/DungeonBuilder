#include "item.h"

namespace core::items {

Item::Item(std::string name) : _name{name} {}

std::ostream& operator<<(std::ostream& out, const Item& item) {
    return out << item.name();
}

const std::string Item::name() const {
    return _name;
}

char Item::displayCharacter() const {
    return 'L';
}

}
