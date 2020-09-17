#include "enchantedlibrary.h"
#include "core/dungeon/roomedge.h"

namespace core::dungeon::magical {

EnchantedLibrary::EnchantedLibrary(const int id) : Room{id} {}

const std::string EnchantedLibrary::description() const {
    std::string description = "The most magical place to learn something. (Enchanted Library)\n"
                              "To the NORTH is " + _north->description() + "\n" +
                              "To the SOUTH is " + _south->description() + "\n" +
                              "To the EAST is " + _east->description() + "\n" +
                              "To the WEST is " + _west->description();
    if (_creature) {
        description += "\nThere is a " + _creature->name() + " to fight.";
    }
    if (_item) {
        description += "\nThere is a " + _item->name() + " to pick up.";
    }

    return description;
}
}
