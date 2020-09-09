#include "enchantedlibrary.h"

namespace core::dungeon::magical {

EnchantedLibrary::EnchantedLibrary(const int id) : Room{id} {
    std::cout << "Created EnchantedLibrary" << std::endl;
}

EnchantedLibrary::~EnchantedLibrary() {
    std::cout << "Destroyed EnchantedLibrary" << std::endl;
}

const std::string EnchantedLibrary::description() const {
    return "The most magical place to learn something (Enchanted Library)";
}

}
