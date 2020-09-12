#include "game.h"

namespace core {

Game* Game::theInstance{nullptr};

Game::Game() : _builder{nullptr}, _level{nullptr} {
    std::cout << "Created Game" << std::endl;
}

Game::~Game() {
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

//void Game::setDungeonType(core::dungeon::DungeonLevelBuilder* builder) {
//    if (_builder) {
//        delete builder;
//        _builder = nullptr;
//    }
//    _builder = builder;
//}

void Game::setDungeonType(std::unique_ptr<core::dungeon::DungeonLevelBuilder> builder) {
    _builder = std::move(builder);
}

void Game::createExampleLevel() {
    _builder->BuildDungeonLevel("Example", 1, 2);
}

void Game::createRandomLevel(const std::string& name, const int width, const int height) {
    if (_level) {
        delete _level;
        _level = nullptr;
    }
    _builder->BuildDungeonLevel(name, width, height);
    _level = _builder->getDungeonLevel();
}

void Game::displayLevel() const {

}

double Game::randomDouble() {
    return _realDistribution(_randomGenerator);
}


}
