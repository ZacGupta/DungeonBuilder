#ifndef MENUINTERFACE_H
#define MENUINTERFACE_H

#include <iostream>
#include <unordered_set>

namespace core {

class MenuInterface {

  public:
    //!< @brief This class cannot be instantiated without specifying references to an ostream and istream object.
    MenuInterface() = delete;
    MenuInterface(const MenuInterface& other) = default;
    ~MenuInterface() = default;

    //!< @brief The constructor requires a reference to an ostream and istream object.
    MenuInterface(std::ostream& _display, std::istream& _input);
    void displayWelcome (const std::string& author, const std::string& title) const;
    //!< @brief displays the menu interface to the console.
    void run() const;

  private:
    std::ostream& _display;
    std::istream& _input;

    void mainMenu() const;
    void describeViewMenu() const;
    void explorationMenu() const;

    /** @brief validates user input for alphabetical values.
      * @returns true if the char exists in the set.
     */
    bool isValidOption(const std::unordered_set<char>& menuOptions, const char& userInput) const;

    /** @brief Validates user input for numeric values.
      * @returns true if the char is an integer between 1-4 inclusive.
     */
    bool isValidInteger(const char& userInput) const;
};
}

#endif // MENUINTERFACE_H
