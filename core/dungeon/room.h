#ifndef ROOM_H
#define ROOM_H

#include "core/creatures/abstractcreature.h"
#include "core/items/item.h"
#include <string>
#include <vector>
#include <memory>


namespace core::dungeon {

enum class Direction : unsigned {North, East, South, West};

class RoomEdge;

class Room {
  public:
    Room() = delete;
    Room(const Room& other) = delete;
    virtual ~Room();

    friend std::ostream& operator<<(std::ostream& out, const Room& room);
    //!< @brief << operator is overloaded to provide a description of the dungeon room.

    virtual const std::string description() const = 0;
    //!< @brief Returns a description of itself, which includes all room edges,
    //! as well as any creatures and items if present.

    virtual std::vector<std::string> display() const;
    //!< @brief Returns an ASCII-style display of the dungeon room.

    int id() const;
    //!< @brief Returns the room ID.

    const core::items::Item& item() const;
    //!< @brief Returns a reference to the item present in the room, if no item is present, a nullptr is returned.

    core::creatures::AbstractCreature& creature() const;
    //!< @brief Returns a reference to the creature present in the room, if no creature is present, a nullptr is returned.

    RoomEdge* north() const;
    //!< @brief Returns a pointer to the northern RoomEdge.

    RoomEdge* south() const;
    //!< @brief Returns a pointer the southern RoomEdge.

    RoomEdge* east() const;
    //!< @brief Returns a pointer the eastern RoomEdge.

    RoomEdge* west() const;
    //!< @brief Returns a pointer the western RoomEdge.

    void setItem(std::unique_ptr<core::items::Item> newItem);
    //!< @brief Adds the specified Item to the room.

    void setCreature(std::unique_ptr<core::creatures::AbstractCreature> newCreature);
    //!< @brief Adds the specified AbstractCreature to the room.

    void setEdge(RoomEdge* edge, Direction direction);
    //!< @brief Adds the specified RoomEdge object to the room, at the specified Direction.

  protected:
    Room(const int id);
    const int _id;
    std::unique_ptr<core::items::Item> _item;
    std::unique_ptr<core::creatures::AbstractCreature> _creature;
    RoomEdge* _north;
    RoomEdge* _south;
    RoomEdge* _east;
    RoomEdge* _west;
};
}
#endif // ROOM_H
