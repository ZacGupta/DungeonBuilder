#ifndef CONSUMABLE_H
#define CONSUMABLE_H

#include "core/items/item.h"

namespace core::items {

class Consumable : public Item {
  public:
    Consumable() = delete;
    Consumable(const Consumable& other) = default;

    Consumable(std::string name);
    ~Consumable();
    virtual std::unique_ptr<Item> clone() override;
};
}
#endif // CONSUMABLE_H
