#include "game.h"

namespace core {

Game* Game::theInstance{nullptr};

Game::Game() : _builder{nullptr} {
    std::cout << "Created Game" << std::endl;
}

Game::~Game() {
    delete theInstance;
    theInstance = nullptr;
    std::cout << "Destroyed Game" << std::endl;
}

Game* Game::instance() {
    if (not theInstance) {
        theInstance = new Game;
        return theInstance;
    }
    std::cout << "A previous instance already exists" << std::endl;
    return nullptr;
}

void Game::setDungeonType(core::dungeon::DungeonLevelBuilder* builder) {
    if (_builder) {
        delete builder;
        _builder = nullptr;
    }
    _builder = builder;
}

//void Game::setDungeonType(std::shared_ptr<core::dungeon::DungeonLevelBuilder> builder) {
//    _builder = builder;
//}

void Game::createExampleLevel() const {

}

void Game::createRandomLevel(const std::string& name, const int width, const int height) const {

}

void Game::displayLevel() const {

}

double Game::randomDouble() {
    return _realDistribution(_randomGenerator);
}


}
