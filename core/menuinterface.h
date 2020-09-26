#ifndef MENUINTERFACE_H
#define MENUINTERFACE_H

#include <core/game.h>
#include <unordered_set>

namespace core {

class MenuInterface {

  public:
    MenuInterface() = delete;
    MenuInterface(const MenuInterface& other) = delete;
    ~MenuInterface() = default;
    MenuInterface(std::ostream& _display, std::istream& _input);
    //!< @brief The constructor requires a reference to an ostream and istream object.

    void displayWelcome (const std::string& author, const std::string& title) const;
    //!< @brief displays the author and title of this project.

    void run();
    //!< @brief displays a text-based menu interface.

  private:
    std::ostream& _display;
    std::istream& _input;
    int _numOfRooms;

    void mainMenu();
    void describeViewMenu();
    void explorationMenu();

    bool isValidOption(const std::unordered_set<char>& menuOptions, const char userInput) const;
    bool isValidDimension(const int userInput) const;
    bool isValidRoomNumber(const int userinPut) const;
};
}

#endif // MENUINTERFACE_H
