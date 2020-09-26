#ifndef DUNGEONLEVEL_H
#define DUNGEONLEVEL_H

#include "core/dungeon/room.h"
#include <string>

namespace core::dungeon {

class DungeonLevel {
  public:
    DungeonLevel() = delete;
    DungeonLevel (const DungeonLevel& other) = delete;
    virtual ~DungeonLevel() = default;

    friend std::ostream& operator<<(std::ostream& out, const DungeonLevel& dungeonLevel);
    //!< @brief << operator is overloaded to describe the dungeon.

    virtual bool addRoom(std::shared_ptr<Room> room);
    //!< @brief Adds the specified room to the dungeon, returns true if successful.

    virtual std::shared_ptr<Room> retrieveRoom(int id) const;
    //!< @brief Returns a shared pointer to the specified room in the dungeon.

    virtual int width() const;
    //!< @brief Returns the width the dungeon.

    virtual int height() const;
    //!< @brief Returns the height the dungeon.

    virtual int numberOfRooms() const;
    //!< @brief returns the total number of rooms inside the dungeon.

    virtual const std::string& name() const;
    //!< @brief returns the name of the dungeon

    virtual const std::string description() const = 0;
    //!< @brief Returns the description of the dungeon, which includes the name, size and dungeon type.

    virtual const std::vector<std::string> display() const;
    //!< @brief Returns an ASCII-style display of the dungeon.
  protected:
    DungeonLevel(const std::string& name, int width, int height);
    const std::string _name;
    int _width;
    int _height;
    const int _numberOfRooms;
    std::vector<std::shared_ptr<Room>> _rooms;
    std::vector<std::vector<std::string>> buildDisplay() const;
};
}

#endif // DUNGEONLEVEL_H
