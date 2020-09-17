#ifndef GAME_H
#define GAME_H

#include "core/dungeon/dungeonlevelbuilder.h"
#include <core/dungeon/dungeonlevel.h>
#include <string>
#include <random>
#include <ctime>

namespace core {

class Game {
  public:
    Game(const Game& other) = delete;
    Game& operator=(const Game&) = delete;

    ~Game();

    static Game* instance();
    //void setDungeonType(core::dungeon::DungeonLevelBuilder* builder);
    void setDungeonType(std::unique_ptr<core::dungeon::DungeonLevelBuilder> builder);
    void createExampleLevel();
    void createRandomLevel(const std::string& name, const int width, const int height);


    const std::ostream& displayLevel(std::ostream& out) const;
    const std::ostream& describeDungeon(std::ostream& out) const;
    const std::ostream& describeRoom(const int id, std::ostream& out) const;

  private:
    Game();

    double randomDouble();
    int randomInt(int possibilities) const;

    static Game* theInstance;
    std::unique_ptr<core::dungeon::DungeonLevelBuilder> _builder;
    core::dungeon::DungeonLevel* _level;

    std::mt19937 _randomGenerator{uint32_t(time(nullptr))}; //!< Mersenne Twister random number generator seeded by current time
    std::uniform_real_distribution<double> _realDistribution{0.0, 1.0}; //!< For random numbers between 0.0 & 1.0

};
}

#endif // GAME_H
