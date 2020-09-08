#include "menuinterface.h"

namespace core {

MenuInterface::MenuInterface(std::ostream& display, std::istream& input)
    : display{display}, input{input},
      mainMenuOptions{'g', 'r', 'q'}, describeViewOptions{'d', 'v', 'r'},
      explorationOptions{'d', 'r'} {
}

void MenuInterface::displayWelcome(const std::string& author, const std::string& title) const {
    display << "Welcome to: " + title << std::endl
            << "                  Developed by " + author << std::endl
            << "           COMP 3023 Software Development with C++\n" << std::endl;
}

void MenuInterface::run() {
    mainMenu();
}

void MenuInterface::mainMenu() const {
    std::string userInput;
    char choice;

    display << "What would you like to do" << std::endl
            << " (g)enerate the example level" << std::endl
            << " (r)andom dungeon level" << std::endl
            << " (q)uit" << std::endl;
    input >> userInput;

    if (userInput.length() == 1 and isValidOption(mainMenuOptions, userInput.front())) {
        choice  = userInput.front();

        //Generate Example Dungeon
        if (choice == 'g') {
            display << "\nCreating example dungeon level..." << std::endl
                    << "Dungeon level created!\n" << std::endl;
            describeViewMenu();
          //Generate Random Dungeon
        } else if (choice == 'r') {
            std::string dungeonName;
            char rows;
            char columns;
            char dungeonType;
            //Get name
            do {
                display << "\nWhat would you like to call the level?" << std::endl;
                input.ignore();
                std::getline(input, dungeonName);

                if (input.fail() or dungeonName.empty()) {
                    input.clear();
                    input.ignore();
                    display << "\nDungeon Name can not be empty\n" << std::endl;
                }

            } while (dungeonName.empty());

            //Get rows
            do {

                display << "\nHow many rows in " << "*" << dungeonName << "*?" << std::endl;
                input >> userInput;

                if (userInput.length() == 1) {
                    rows = userInput.front();
                }

                if (input.fail() or not isValidDimension(rows)) {
                    input.clear();
                    input.ignore();
                    display << "\nInvalid input option" << std::endl
                            << "Please enter a value between 1-4 (inclusive)" << std::endl;
                }
            } while (not isValidDimension(rows));

            //Get columns
            do {
                display << "\nHow many columns in " << "*" << dungeonName << "*?" << std::endl;
                input >> userInput;

                if (userInput.length() == 1) {
                    columns = userInput.front();
                }

                if (input.fail() or not isValidDimension(columns)) {
                    input.clear();
                    input.ignore();
                    display << "\nInvalid input option" << std::endl
                            << "Please enter a value between [1-4] (inclusive)" << std::endl;
                }
            } while (not isValidDimension(columns));

            //Get type
            do {
                display << "\nWhat type of dungeon level is it? (b)asic or (m)agical" << std::endl;
                input >> userInput;

                if (userInput.length() == 1) {
                    dungeonType = userInput.front();
                }

                if (input.fail() or (dungeonType != 'b' and dungeonType != 'm')) {
                    input.clear();
                    input.ignore();
                    display << "\nInvalid input option" << std::endl
                            << "Please enter either ['b' or 'm']" << std::endl;
                }
            } while (dungeonType != 'b' and dungeonType != 'm');

            display << "\nCreating " << dungeonName << "..." << std::endl
                    << "Dungeon level created!\n" << std::endl;
            describeViewMenu();
        }
        //Quit
        else {
            char quitChoice;
            //Confirm quit
            do {
                display << "\n*Are you sure you want to quit? (y/n)*" << std::endl;
                input >> userInput;

                if (userInput.length() == 1) {
                    quitChoice = userInput.front();
                }

                if (input.fail() or (quitChoice != 'y' and quitChoice != 'n')) {
                    display << "in if" << std::endl;
                    input.clear();
                    input.ignore();
                    display << "\nInvalid input option" << std::endl
                            << "Please enter either ['y' or 'n']" << std::endl;
                }
            } while (quitChoice != 'y' and quitChoice != 'n');

            if (quitChoice == 'y') {
                display << "\nGoodbye!" << std::endl;
            } else {
                input.ignore();
                input.clear();
                display << std::endl;
                mainMenu();
            }
        }
    } else {
        input.ignore();
        input.clear();
        display << "\nInvalid input option" << std::endl
                << "Please select between ['g', 'r', 'q']\n" << std::endl;
        mainMenu();
    }


}

void MenuInterface::describeViewMenu() const {
    display << "In describeViewMenu()" << std::endl;
}

void MenuInterface::explorationMenu() const {
    display << "In explorationwMenu()" << std::endl;
}

bool MenuInterface::isValidOption(const std::unordered_set<char>& menuOptions, const char& userInput) const {
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
