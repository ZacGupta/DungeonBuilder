#include "game.h"

namespace core {

Game::Game() {

}

double Game::randomDouble() {
    return _realDistribution(_randomGenerator);
}


}
