#ifndef ENCHANTEDLIBRARY_H
#define ENCHANTEDLIBRARY_H

#include "core/dungeon/room.h"

namespace core::dungeon::magical {

class EnchantedLibrary : public Room {
  public:
    EnchantedLibrary() = delete;
    EnchantedLibrary(const EnchantedLibrary& other) = delete;
    ~EnchantedLibrary() = default;
    EnchantedLibrary(const int id);
    //!< @brief The constructor requires the id of the room to be created.

    virtual const std::string description() const override;
    //!< @brief Returns a description of the room, including all room edges, as well as any creatures and items if present.
};
}


#endif // ENCHANTEDLIBRARY_H
