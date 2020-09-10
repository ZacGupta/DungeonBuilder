#ifndef MAGICDUNGEONLEVEL_H
#define MAGICDUNGEONLEVEL_H

#include "core/dungeon/dungeonlevel.h"

namespace core::dungeon::magical {

class MagicDungeonLevel : public DungeonLevel {
  public:
    MagicDungeonLevel() = delete;
    MagicDungeonLevel (const MagicDungeonLevel& other) = delete;

    MagicDungeonLevel(const std::string& name, int width, int height);
    virtual ~MagicDungeonLevel();
    virtual const std::string description() const override;
};
}


#endif // MAGICDUNGEONLEVEL_H
