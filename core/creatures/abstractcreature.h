#ifndef ABSTRACTCREATURE_H
#define ABSTRACTCREATURE_H

#include <string>
#include <memory>

namespace core::creatures {

class AbstractCreature {
  public:
    AbstractCreature() = delete;
    AbstractCreature(const AbstractCreature& other) = default;
    virtual ~AbstractCreature() = default;
    AbstractCreature(std::string name);
    //!< @brief The constructor requires an std::string which represents the name of the AbstractCreature.

    friend std::ostream& operator<<(std::ostream& out, const AbstractCreature& creature);
    //!< @brief The << operator is overloaded to describe the creature.


    const std::string name() const;
    //!< @brief Returns the name of the creature


    char displayCharacter() const;
    //!< @brief Returns the display character for creatures.


    bool isBoss() const;
    //!< @brief Returns true if the creature is a boss.


    void markAsBoss();
    //!< @brief Makes the creature an elite version of itself.


    virtual std::unique_ptr<AbstractCreature> clone() = 0;
    //!< @brief Returns a deep copy of itself when overridden by a derieved class.
  protected:
    std::string _name;
    bool _isBoss;

};
}


#endif // ABSTRACTCREATURE_H
