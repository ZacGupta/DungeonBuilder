#include "quartzchamber.h"
#include "core/dungeon/roomedge.h"

namespace core::dungeon::basic {

QuartzChamber::QuartzChamber(const int id) : Room{id} {}

const std::string QuartzChamber::description() const {
    std::string description = "A chamber that glitters like a thousand stars in the torchlight. (Quartz Chamber)\n"
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
