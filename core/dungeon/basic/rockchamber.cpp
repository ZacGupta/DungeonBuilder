#include "rockchamber.h"
#include "core/dungeon/roomedge.h"

namespace core::dungeon::basic {

RockChamber::RockChamber(const int id) : Room{id} {}

const std::string RockChamber::description() const {
    std::string description = "A dark and empty chamber. (Rock Chamber)\n"
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
