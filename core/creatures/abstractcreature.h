#ifndef ABSTRACTCREATURE_H
#define ABSTRACTCREATURE_H

#include <string>
#include <memory>
#include <iostream> //DELETE THIS

namespace core::creatures {

class AbstractCreature {
  public:
    AbstractCreature() = delete;
    AbstractCreature(const AbstractCreature& other) = delete;

    AbstractCreature(std::string name);
    virtual ~AbstractCreature();

    std::string name();
    char displayCharacter();
    void markAsBoss();
    bool isBoss();
    virtual std::unique_ptr<AbstractCreature> clone() = 0;
  protected:
    std::string _name;
    bool _isBoss;
};
}


#endif // ABSTRACTCREATURE_H
