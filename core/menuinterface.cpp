#include "menuinterface.h"

namespace core {

MenuInterface::MenuInterface(std::ostream& display, std::istream& input)
    : _display{display}, _input{input},
      mainMenuOptions{'g', 'r', 'q'}, describeViewOptions{'d', 'v', 'r'},
      explorationOptions{'d', 'r'}, dungeonOptions{'b', 'm'}   {}

void MenuInterface::displayWelcome(const std::string& author, const std::string& title) const {
    _display << "Welcome to: " + title << std::endl
             << "                  Developed by " + author << std::endl
             << "           COMP 3023 Software Development with C++\n" << std::endl;
}

void MenuInterface::run() {
    mainMenu();
}

void MenuInterface::mainMenu() const {

}

void MenuInterface::describeViewMenu() const {

}

void MenuInterface::explorationMenu() const {

}

bool MenuInterface::isValidOption(const std::set<char>& menuOptions, const char& userInput) const {
    if (menuOptions.count(userInput) == 1) {
        return true;
    } else {
        return false;
    }
}

bool MenuInterface::isValidDimension(const char& userInput) const {
    if (userInput == '1' or userInput == '2' or userInput == '3' or userInput == '4') {
        return true;
    } else {
        return false;
    }
}


}
