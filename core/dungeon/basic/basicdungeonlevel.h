#ifndef BASICDUNGEONLEVEL_H
#define BASICDUNGEONLEVEL_H

#include "core/dungeon/dungeonlevel.h"

namespace core::dungeon::basic {

class BasicDungeonLevel : public DungeonLevel {
  public:
    BasicDungeonLevel() = delete;
    BasicDungeonLevel (const BasicDungeonLevel& other) = delete;
    ~BasicDungeonLevel() = default;
    BasicDungeonLevel(const std::string& name, int width, int height);
    //!< @brief The constructor requires an std::string which represents the name of the dungeon,
    //! as well as integers between 1-4 (inclusive) which represent the size of the dungeon.

    virtual const std::string description() const override;
    //!< @brief Returns a description of the dungeon, which includes the name, size and dungeon type.
};
}

#endif // BASICDUNGEONLEVEL_H
