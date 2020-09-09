#ifndef ROOM_H
#define ROOM_H

#include "core/creatures/abstractcreature.h"
#include "core/items/item.h"
#include <string>
#include <vector>

namespace core {
namespace dungeon {

class Room {
  public:
    Room() = delete;
    Room(const int id);
    virtual ~Room() = default;

    friend std::ostream& operator<<(std::ostream& out, const Room& room);  //operator overload (<<)

    virtual std::string description() const = 0;
    std::vector<std::string> display() const;

    int id() const;

    const core::items::Item& item() const;
    void setItem(const core::items::Item& newItem);

    const core::creatures::AbstractCreature& creature() const;
    void setCreature(const core::creatures::AbstractCreature& newCreature);

  private:
    const int _id;
    core::items::Item _item;
    core::creatures::AbstractCreature _creature;


    enum class Direction : unsigned {North, South, East, West}; // Make sure this is in the correct scope
};
}
}
#endif // ROOM_H
