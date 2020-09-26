#ifndef ALCHEMISTSLABORATORY_H
#define ALCHEMISTSLABORATORY_H

#include "core/dungeon/room.h"

namespace core::dungeon::magical {

class AlchemistsLaboratory : public Room {
  public:
    AlchemistsLaboratory() = delete;
    AlchemistsLaboratory(const AlchemistsLaboratory& other) = delete;
    ~AlchemistsLaboratory() = default;
    AlchemistsLaboratory(const int id);
    //!< @brief The constructor requires the id of the room to be created.

    virtual const std::string description() const override;
    //!< @brief Returns a description of the room, including all room edges, as well as any creatures and items if present.
};
}


#endif // ALCHEMISTSLABORATORY_H
