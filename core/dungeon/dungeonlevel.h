#ifndef DUNGEONLEVEL_H
#define DUNGEONLEVEL_H

#include "core/dungeon/room.h"
#include <string>

namespace core::dungeon {

class DungeonLevel {
  public:
    DungeonLevel() = delete;
    DungeonLevel (const DungeonLevel& other) = delete;
    virtual ~DungeonLevel();

    friend std::ostream& operator<<(std::ostream& out, const DungeonLevel& dungeonLevel);  //operator overload (<<)

    virtual bool addRoom(std::shared_ptr<Room> room);
    virtual std::shared_ptr<Room> retrieveRoom(int id) const;
    virtual int width() const;
    virtual int height() const;
    virtual int numberOfRooms() const;
    virtual const std::string& name() const;
    virtual const std::string description() const = 0;
    virtual const std::vector<std::string> display() const;
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
