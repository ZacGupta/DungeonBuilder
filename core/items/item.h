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

    friend std::ostream& operator<<(std::ostream& out, const Item& item);  //operator overload (<<)

    const std::string name() const;
    char displayCharacter() const;
    virtual std::unique_ptr<Item> clone() = 0;
  protected:
    std::string _name;
};
}

#endif // ITEM_H
