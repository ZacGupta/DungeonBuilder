#ifndef ABSTRACTCREATURE_H
#define ABSTRACTCREATURE_H

#include <string>
#include <memory>

namespace core::creatures {

class AbstractCreature {
  public:
    AbstractCreature() = delete;
    AbstractCreature(const AbstractCreature& other) = delete;

    AbstractCreature(std::string name);
    virtual ~AbstractCreature();

    std::string name();
    char displayCharacter();
    virtual std::unique_ptr<AbstractCreature> clone() = 0;
  protected:
    std::string _name;
};
}


#endif // ABSTRACTCREATURE_H
