#ifndef WEAPON_H
#define WEAPON_H

#include "core/items/item.h"

namespace core::items {

class Weapon : public Item {
  public:
    Weapon() = delete;
    Weapon(const Weapon& other) = default;
    ~Weapon() = default;
    Weapon(std::string name);
    //!< @brief The constructor requires an std::string which represents the name of the weapon.

    virtual std::unique_ptr<Item> clone() override;
    //!< @brief Returns a deep copy of itself.
};
}

#endif // WEAPON_H
