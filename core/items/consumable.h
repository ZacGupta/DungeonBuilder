#ifndef CONSUMABLE_H
#define CONSUMABLE_H

#include "core/items/item.h"

namespace core::items {

class Consumable : public Item {
  public:
    Consumable() = delete;
    Consumable(const Consumable& other) = default;
    ~Consumable() = default;
    Consumable(std::string name);
    //!< @brief The constructor requires an std::string which represents the name of the consumable.

    virtual std::unique_ptr<Item> clone() override;
    //!< @brief Returns a deep copy of itself.
};
}
#endif // CONSUMABLE_H
