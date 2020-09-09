#ifndef ALCHEMISTSLABORATORY_H
#define ALCHEMISTSLABORATORY_H

#include <core/dungeon/room.h>

namespace core::dungeon::magical {

class AlchemistsLaboratory : public Room {
public:
  AlchemistsLaboratory() = delete;
  AlchemistsLaboratory(const AlchemistsLaboratory& other) = delete;
  AlchemistsLaboratory(const int id);
  virtual ~AlchemistsLaboratory();

  virtual const std::string description() const override;
};
}


#endif // ALCHEMISTSLABORATORY_H
