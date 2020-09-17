#ifndef ABSTRACTCREATURE_H
#define ABSTRACTCREATURE_H

#include <string>
#include <memory>

namespace core::creatures {

class AbstractCreature {
  public:
    AbstractCreature() = delete;
    AbstractCreature(const AbstractCreature& other) = default;

    AbstractCreature(std::string name);
    virtual ~AbstractCreature() = default;

    friend std::ostream& operator<<(std::ostream& out, const AbstractCreature& creature);  //operator overload (<<)

    const std::string name() const;
    char displayCharacter() const;
    void markAsBoss();
    bool isBoss() const;
    virtual std::unique_ptr<AbstractCreature> clone() = 0;
  protected:
    std::string _name;
    bool _isBoss;
};
}


#endif // ABSTRACTCREATURE_H
