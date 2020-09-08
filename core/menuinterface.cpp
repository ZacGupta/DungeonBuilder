#include "menuinterface.h"

namespace core {

MenuInterface::MenuInterface(std::ostream& display, std::istream& input)
    : _display{display}, _input{input}, mainMenuOptions{'g', 'r', 'q'}, describeViewOptions{'d', 'v', 'r'}, explorationOptions{'d', 'r'}  {}

void MenuInterface::displayWelcome(const std::string& author, const std::string& title) const {
    _display << "Welcome to: " + title << std::endl
             << "                  Developed by " + author << std::endl
             << "           COMP 3023 Software Development with C++\n" << std::endl;
}

void MenuInterface::run() {

}


}
