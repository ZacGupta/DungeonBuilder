#include "menuinterface.h"
#include <limits>

namespace core {

MenuInterface::MenuInterface(std::ostream& display, std::istream& input) : _display{display}, _input{input} {}

void MenuInterface::displayWelcome(const std::string& author, const std::string& title) const {
    _display << "Welcome to: " + title << std::endl
            << "                  Developed by " + author << std::endl
            << "           COMP 3023 Software Development with C++\n" << std::endl;
}

void MenuInterface::run() const {
    mainMenu();
}

void MenuInterface::mainMenu() const {
    const std::unordered_set<char> menuOptions{'g', 'r', 'q'};
    const std::unordered_set<char> dungeonOptions{'b', 'm'};
    const std::unordered_set<char> quitOptions{'y', 'n'};
    std::string userInput;
    char choice;

    _display << "What would you like to do" << std::endl
            << " (g)enerate the example level" << std::endl
            << " (r)andom dungeon level" << std::endl
            << " (q)uit" << std::endl;
    _input >> userInput;

    //Valid input
    if (userInput.length() == 1 and isValidOption(menuOptions, userInput.front())) {
        choice  = userInput.front();

        //Generate Example Dungeon
        if (choice == 'g') {
            _display << "\nCreating example dungeon level..." << std::endl
                    << "Dungeon level created!\n" << std::endl;
            describeViewMenu();
        }
        //Generate Random Dungeon
        else if (choice == 'r') {
            std::string dungeonName;
            char rows;
            char columns;
            char dungeonType;

            //input.ignore() here fixes a bug.
            _input.ignore();

            //Get name
            do {
                _display << "\nWhat would you like to call the level?" << std::endl;
                std::getline(_input, dungeonName);

                if (dungeonName.empty()) {
                    _display << "\nThe name can not be empty\n" << std::endl;
                }
                if (_input.fail()) {
                    _input.clear();
                    _input.ignore();

                }
            } while (dungeonName.empty());

            //Get rows
            do {

                _display << "\nHow many rows in " << "*" << dungeonName << "*?" << std::endl;
                _input >> userInput;

                if (userInput.length() == 1) {
                    rows = userInput.front();
                }
                if (_input.fail() or not isValidInteger(rows)) {
                    _input.clear();
                    _input.ignore();
                    _display << "\nInvalid input option" << std::endl
                            << "Please enter a value between 1-4 (inclusive)" << std::endl;
                }
            } while (not isValidInteger(rows));

            //Get columns
            do {
                _display << "\nHow many columns in " << "*" << dungeonName << "*?" << std::endl;
                _input >> userInput;

                if (userInput.length() == 1) {
                    columns = userInput.front();
                }
                if (_input.fail() or not isValidInteger(columns)) {
                    _input.clear();
                    _input.ignore();
                    _display << "\nInvalid input option" << std::endl
                            << "Please enter a value between [1-4] (inclusive)" << std::endl;
                }
            } while (not isValidInteger(columns));

            //Get type
            do {
                _display << "\nWhat type of dungeon level is it? (b)asic or (m)agical" << std::endl;
                _input >> userInput;

                if (userInput.length() == 1) {
                    dungeonType = userInput.front();
                }

                if (_input.fail() or not isValidOption(dungeonOptions, dungeonType)) {
                    _input.clear();
                    _input.ignore();
                    _display << "\nInvalid input option" << std::endl
                            << "Please enter either ['b' or 'm']" << std::endl;
                }
            } while (not isValidOption(dungeonOptions, dungeonType));

            _display << "\nCreating " << dungeonName << "..." << std::endl
                    << "Dungeon level created!\n" << std::endl;
            describeViewMenu();
        }
        //Quit
        else {
            char quitChoice;

            do {
                _display << "\n*Are you sure you want to quit? (y/n)*" << std::endl;
                _input >> userInput;

                if (userInput.length() == 1) {
                    quitChoice = userInput.front();
                }
                if (_input.fail() or not isValidOption(quitOptions, quitChoice)) {
                    _input.clear();
                    _input.ignore();
                    _display << "\nInvalid input option" << std::endl
                            << "Please enter either ['y' or 'n']" << std::endl;
                }
            } while (not isValidOption(quitOptions, quitChoice));

            if (quitChoice == 'y') {
                _display << "\nGoodbye!" << std::endl;
            } else {
                _input.clear();
                _input.ignore();
                _display << std::endl;
                mainMenu();
            }
        }
    }
    //Invalid input for main choice leads here.
    else {
        _input.clear();
        _input.ignore();
        _display << "\nInvalid input option" << std::endl
                << "Please select between ['g', 'r', 'q']\n" << std::endl;
        mainMenu();
    }
}

void MenuInterface::describeViewMenu() const {
    const std::unordered_set<char> menuOptions {'d', 'v', 'r'};
    std::string userInput;
    char choice;

    _display << "What would you like to do" << std::endl
            << " (d)escribe the dungeon level" << std::endl
            << " (v)iew the dungeon level" << std::endl
            << " (r)eturn to the main menu" << std::endl;
    _input >> userInput;

    //Valid input
    if (userInput.length() == 1 and isValidOption(menuOptions, userInput.front())) {
        choice  = userInput.front();
        //Describe Dungeon
        if (choice == 'd') {
            _display << "\n[DESCRIBE DUNGEON]\n" << std::endl;
            explorationMenu();
        }
        //View Dungeon
        else if (choice == 'v') {
            _display << "\n[PRINT DUNGEON]\n" << std::endl;
            _display << "Press ENTER to continue" << std::endl;
            _input.sync();
            _input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            describeViewMenu();
        }
        //Return to Main Menu
        else {
            _display << "\nReturning to main menu.\n" << std::endl;
            mainMenu();
        }
    }
    //Invalid input.
    else {
        _input.clear();
        _input.ignore();
        _display << "\nInvalid input option" << std::endl
                << "Please select between ['d', 'v', 'r']\n" << std::endl;
        describeViewMenu();
    }

}

void MenuInterface::explorationMenu() const {
    const std::unordered_set<char> menuOptions{'d', 'r'};
    std::string userInput;
    char choice;

    _display << "What would you like to do" << std::endl
            << " (d)escribe a room" << std::endl
            << " (r)eturn to previous menu" << std::endl;
    _input >> userInput;

    //Valid input
    if (userInput.length() == 1 and isValidOption(menuOptions, userInput.front())) {
        choice  = userInput.front();
        //Describe the room.
        if (choice == 'd') {
            char roomNumber;
            //Get Room Number.
            do {
                _display << "\nWhich room would you like to describe? (1-4)" << std::endl;
                _input >> userInput;

                if (userInput.length() == 1) {
                    roomNumber = userInput.front();
                }
                if (_input.fail() or not isValidInteger(roomNumber)) {
                    _input.clear();
                    _input.ignore();
                    _display << "\nInvalid input option" << std::endl
                            << "Please enter a value between [1-4] (inclusive)" << std::endl;
                }
            } while (not isValidInteger(roomNumber));

            _display << "Room *" << roomNumber << "* is..." << std::endl;
            _display << "[DESCRIBE ROOM]\n" << std::endl;
            _display << "Press ENTER to continue" << std::endl;
            _input.sync();
            _input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            explorationMenu();

        }
        //Return to Describe/View Menu.
        else {
            _display << "\nReturning to describe/view menu.\n" << std::endl;
            describeViewMenu();
        }
    }
    //Invalid input.
    else {
        _input.clear();
        _input.ignore();
        _display << "\nInvalid input option" << std::endl
                << "Please select between ['d', 'v', 'r']\n" << std::endl;
        explorationMenu();
    }

}

bool MenuInterface::isValidOption(const std::unordered_set<char>& menuOptions, const char& userInput) const {
    if (menuOptions.count(userInput) == 1) {
        return true;
    } else {
        return false;
    }
}

bool MenuInterface::isValidInteger(const char& userInput) const {
    if (userInput == '1' or userInput == '2' or userInput == '3' or userInput == '4') {
        return true;
    } else {
        return false;
    }
}


}
