#ifndef MENUINTERFACE_H
#define MENUINTERFACE_H

#include <iostream>
#include <set>

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
    std::ostream& _display;
    std::istream& _input;
    const std::set<char> mainMenuOptions;
    const std::set<char> describeViewOptions;
    const std::set<char> explorationOptions;

};
}

#endif // MENUINTERFACE_H
