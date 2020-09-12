#include "quartzchamber.h"

namespace core::dungeon::basic {

QuartzChamber::QuartzChamber(const int id) : Room{id} {}

const std::string QuartzChamber::description() const {
    return "A chamber that glitters like a thousand stars in the torchlight. (Quartz Chamber)";
}

}
