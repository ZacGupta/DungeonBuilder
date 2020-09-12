#include "enchantedlibrary.h"

namespace core::dungeon::magical {

EnchantedLibrary::EnchantedLibrary(const int id) : Room{id} {}

const std::string EnchantedLibrary::description() const {
    return "The most magical place to learn something (Enchanted Library)";
}

}
