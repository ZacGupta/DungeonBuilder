#ifndef GAME_H
#define GAME_H

#include <string>
#include <random>
#include <ctime>

namespace core {

class Game {
  public:
    Game(const Game& other) = delete;
    Game& operator=(const Game&) = delete;

    ~Game();

    const Game* instance() const;
    void setDungeonType() const; //@Param DungeonLevelBuilder
    void createExxampleLevel() const;
    void createRandomLevel(const std::string& name, const int width, const int height) const;
    void displayLevel() const;
    double randomDouble();
  private:
    Game();

    std::mt19937 _randomGenerator{uint32_t(time(nullptr))}; //!< Mersenne Twister random number generator seeded by current time
    std::uniform_real_distribution<double> _realDistribution{0.0, 1.0}; //!< For random numbers between 0.0 & 1.0
};
}

#endif // GAME_H
