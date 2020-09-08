#ifndef MENUINTERFACE_H
#define MENUINTERFACE_H

#include <iostream>
#include <unordered_set>

namespace core {

class MenuInterface {

  public:
    MenuInterface() = delete;
    MenuInterface(MenuInterface& other) = default;
    ~MenuInterface() = default;

    /** @brief The constructor requires a reference to an ostream and istream object. */
    MenuInterface(std::ostream& _display, std::istream& _input);

    /** @brief prints the author's name and the title of this project to the console. */
    void displayWelcome (const std::string& author, const std::string& title) const;

    /** @brief displays the menu interface to the console. */
    void run() const;

  private:
    std::ostream& _display;
    std::istream& _input;

    /** @brief Responsible for the main menu interface */
    void mainMenu() const;
    /** @brief Responsible for the describe/view menu interface */
    void describeViewMenu() const;
    /** @brief Responsible for the exploration menu interface */
    void explorationMenu() const;

    /** @brief isValidOption() requires a set of valid menu options, and a char.
      * @returns true if the char exists in the set.
     */
    bool isValidOption(const std::unordered_set<char>& menuOptions, const char& userInput) const;

    /** @brief isValidOption() requires a char.
      * @returns true if the char is an integer between 1-4 inclusive.
     */
    bool isValidInteger(const char& userInput) const;
};
}

#endif // MENUINTERFACE_H
