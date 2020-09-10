#ifndef MONSTER_H
#define MONSTER_H

#include <core/creatures/abstractcreature.h>

namespace core::creatures {

class Monster : public AbstractCreature {
  public:
    Monster() = delete;
    Monster(const Monster& other) = default;

    Monster(std::string name);
    ~Monster();
    void setName(std::string name);

    virtual std::unique_ptr<AbstractCreature> clone() override;
};
}

#endif // MONSTER_H
