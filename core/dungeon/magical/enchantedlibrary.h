#ifndef ENCHANTEDLIBRARY_H
#define ENCHANTEDLIBRARY_H

#include "core/dungeon/room.h"

namespace core::dungeon::magical {

class EnchantedLibrary : public Room {
  public:
    EnchantedLibrary() = delete;
    EnchantedLibrary(const EnchantedLibrary& other) = delete;
    EnchantedLibrary(const int id);
    virtual ~EnchantedLibrary() = default;

    virtual const std::string description() const override;
};
}


#endif // ENCHANTEDLIBRARY_H
