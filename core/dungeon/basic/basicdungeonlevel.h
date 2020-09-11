#ifndef BASICDUNGEONLEVEL_H
#define BASICDUNGEONLEVEL_H

#include "core/dungeon/dungeonlevel.h"

namespace core::dungeon::basic {

class BasicDungeonLevel : public DungeonLevel {
  public:
    BasicDungeonLevel() = delete;
    BasicDungeonLevel (const BasicDungeonLevel& other) = delete;

    BasicDungeonLevel(const std::string& name, int width, int height);
    virtual ~BasicDungeonLevel();
    virtual const std::string description() const override;

};

}

#endif // BASICDUNGEONLEVEL_H
