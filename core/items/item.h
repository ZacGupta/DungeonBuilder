#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <memory>

namespace core::items {

class Item {
  public:
    Item() = delete;
    Item(const Item& other) = default;

    Item(std::string name);
    virtual ~Item() = default;

    std::string name();
    char displayCharacter();
    virtual std::unique_ptr<Item> clone() = 0;
  protected:
    std::string _name;
};
}

#endif // ITEM_H
