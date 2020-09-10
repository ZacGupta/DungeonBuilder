#ifndef ABSTRACTCREATURE_H
#define ABSTRACTCREATURE_H

#include <string>
#include <memory>
#include <iostream> //DELETE THIS

namespace core::creatures {

class AbstractCreature {
  public:
    AbstractCreature() = delete;
    AbstractCreature(const AbstractCreature& other) = default;

    AbstractCreature(std::string name);
    virtual ~AbstractCreature();

    std::string name();
    char displayCharacter();
    void markAsBoss();
    bool isBoss();
    virtual std::unique_ptr<AbstractCreature> clone() = 0;
        std::string _name;
  protected:

    bool _isBoss;
};
}


#endif // ABSTRACTCREATURE_H
