#ifndef MENUINTERFACE_H
#define MENUINTERFACE_H

#include <iostream>
#include <unordered_set>

namespace core {

class MenuInterface {

  public:
    MenuInterface() = delete;
    ~MenuInterface() = default;
    MenuInterface(MenuInterface& other) = default;

    MenuInterface(std::ostream& display, std::istream& input);
    void displayWelcome (const std::string& author, const std::string& title) const;
    void run();

  private:
    std::ostream& display;
    std::istream& input;

    void mainMenu() const;
    void describeViewMenu() const;
    void explorationMenu() const;
    void resetInput() const;
    bool isValidOption(const std::unordered_set<char>& menuOptions, const char& userInput) const;
    bool isValidDimension(const char& userInput) const;
};
}

#endif // MENUINTERFACE_H
