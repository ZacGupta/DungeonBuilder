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
    //!< @brief Returns a pointer to an instance of this class if one doesn't already exist.

    void setDungeonType(std::unique_ptr<core::dungeon::DungeonLevelBuilder> builder);
    //!< @brief Sets the dungeon type (basic or magical) using a DungeonLevelBuilder object, which can then be used to create a level.
    //!  This method will delete any pre existing DungeonLevel and DungeonLevelBuilder objects.

    void createExampleLevel();
    //!< @brief Generates a preset 3x3 basic dungeon level.

    void createRandomLevel(const std::string& name, const int width, const int height);
    //!< @brief Generates a random dungeon level based on the width and height parameters, which must be integers between 1-4 (inclusive).

    const std::ostream& displayLevel(std::ostream& out) const;
    //!< @brief Displays the current dungeon level.

    const std::ostream& describeDungeon(std::ostream& out) const;
    //!< @brief Displays the name, size and type of the current dungeon level.

    const std::ostream& describeRoom(const int id, std::ostream& out) const;
    //!< @brief Displays a description of each room edge in a specified room in the current dungeon, as well as any creatures and items if present.

  private:
    Game();
    double randomDouble();
    int randomInt(int possibilities) const;

    static Game* theInstance;
    std::unique_ptr<core::dungeon::DungeonLevelBuilder> _builder;
    core::dungeon::DungeonLevel* _level;
    std::mt19937 _randomGenerator{uint32_t(time(nullptr))};
    std::uniform_real_distribution<double> _realDistribution{0.0, 1.0};

};
}

#endif // GAME_H
