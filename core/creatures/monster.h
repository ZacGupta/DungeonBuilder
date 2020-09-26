#ifndef MONSTER_H
#define MONSTER_H

#include <core/creatures/abstractcreature.h>

namespace core::creatures {

class Monster : public AbstractCreature {
  public:
    Monster() = delete;
    Monster(const Monster& other) = default;
    ~Monster() = default;
    Monster(std::string name);
    //!< @brief The constructor requires an std::string which represents the name of the monster.

    virtual std::unique_ptr<AbstractCreature> clone() override;
    //!< @brief Returns a deep copy of itself.
};
}

#endif // MONSTER_H
