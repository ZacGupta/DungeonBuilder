#ifndef WEAPON_H
#define WEAPON_H

#include "core/items/item.h"

namespace core::items {

class Weapon : public Item {
  public:
    Weapon() = delete;
    Weapon(const Weapon& other) = default;

    Weapon(std::string name);
    ~Weapon() = default;

    virtual std::unique_ptr<Item> clone() override;
};
}

#endif // WEAPON_H
