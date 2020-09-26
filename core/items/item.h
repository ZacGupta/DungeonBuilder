#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <memory>

namespace core::items {

class Item {
  public:
    Item() = delete;
    Item(const Item& other) = default;
    virtual ~Item() = default;
    Item(std::string name);
    //!< @brief The constructor requires an std::string which represents the name of the Item.

    friend std::ostream& operator<<(std::ostream& out, const Item& item);
    //!< @brief The << operator is overloaded to describe the item.

    const std::string name() const;
    //!< @brief Returns the name of the item.

    char displayCharacter() const;
    //!< @brief Returns the display character for items.

    virtual std::unique_ptr<Item> clone() = 0;
    //!< @brief Returns a deep copy of itself when overridden by a derieved class.
  protected:
    std::string _name;
};
}

#endif // ITEM_H
