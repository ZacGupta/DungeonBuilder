#include "menuinterface.h"
#include <iostream>
#include <core/dungeon/basic/basicdungeonlevelbuilder.h>
#include <core/dungeon/magical/magicdungeonlevelbuilder.h>

namespace core {

static Game* game{game->instance()};

MenuInterface::MenuInterface(std::ostream& display, std::istream& input) : _display{display}, _input{input}, _numOfRooms{0} {
}

void MenuInterface::displayWelcome(const std::string& author, const std::string& title) const {
    _display << "Welcome to: " + title << std::endl
             << "                  Developed by " + author << std::endl
             << "           COMP 3023 Software Development with C++\n" << std::endl;
}

void MenuInterface::run() {
    mainMenu();
}

void MenuInterface::mainMenu() {
    const std::unordered_set<char> menuOptions{'g', 'r', 'q'};
    const std::unordered_set<char> dungeonOptions{'b', 'm'};
    const std::unordered_set<char> quitOptions{'y', 'n'};
    std::string userInput{""};
    char choice{' '};

    _display << "What would you like to do" << std::endl
             << " (g)enerate the example level" << std::endl
             << " (r)andom dungeon level" << std::endl
             << " (q)uit" << std::endl;
    _input >> userInput;

    //Valid input
    if (userInput.length() == 1 and isValidOption(menuOptions, std::tolower(userInput.front()))) {
        choice  = std::tolower(userInput.front());

        //Generate Example Dungeon
        if (choice == 'g') {
            _display << "\nCreating example dungeon level..." << std::endl;
            std::unique_ptr<core::dungeon::basic::BasicDungeonLevelBuilder> basicDLB{new core::dungeon::basic::BasicDungeonLevelBuilder()};
            game->setDungeonType(std::move(basicDLB));
            game->createExampleLevel();
            _numOfRooms = 9;
            _display << "Dungeon level created!\n" << std::endl;
            describeViewMenu();
        }
        //Generate Random Dungeon
        else if (choice == 'r') {
            std::string dungeonName{""};
            int rows{0};
            int columns{0};
            char dungeonType{' '};

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
                _input >> rows;

                if (_input.fail() or not isValidDimension(rows)) {
                    _input.clear();
                    _input.ignore();
                    _display << "\nInvalid input option" << std::endl
                             << "Please enter a value between 1-4 (inclusive)" << std::endl;
                }
            } while (_input.fail() or not isValidDimension(rows));

            //Get columns
            do {
                _display << "\nHow many columns in " << "*" << dungeonName << "*?" << std::endl;
                _input >> columns;

                if (_input.fail() or not isValidDimension(columns)) {
                    _input.clear();
                    _input.ignore();
                    _display << "\nInvalid input option" << std::endl
                             << "Please enter a value between [1-4] (inclusive)" << std::endl;
                }
            } while (_input.fail() or not isValidDimension(columns));

            //Get type
            do {
                _display << "\nWhat type of dungeon level is it? (b)asic or (m)agical" << std::endl;
                _input >> userInput;

                if (userInput.length() == 1) {
                    dungeonType = std::tolower(userInput.front());
                }

                if (_input.fail() or not isValidOption(dungeonOptions, dungeonType)) {
                    _input.clear();
                    _input.ignore();
                    _display << "\nInvalid input option" << std::endl
                             << "Please enter either ['b' or 'm']" << std::endl;
                }
            } while (not isValidOption(dungeonOptions, dungeonType));

            _display << "\nCreating " << dungeonName << "..." << std::endl;
            if (dungeonType == 'b') {
                std::unique_ptr<core::dungeon::basic::BasicDungeonLevelBuilder> basicDLB{new core::dungeon::basic::BasicDungeonLevelBuilder()};
                game->setDungeonType(std::move(basicDLB));
                game->createRandomLevel(dungeonName, rows, columns);
            } else {
                std::unique_ptr<core::dungeon::magical::MagicDungeonLevelBuilder> magicDLB{new core::dungeon::magical::MagicDungeonLevelBuilder()};
                game->setDungeonType(std::move(magicDLB));
                game->createRandomLevel(dungeonName, rows, columns);
            }
            _numOfRooms = rows * columns;
            _display << "Dungeon level created!\n" << std::endl;
            describeViewMenu();
        }
        //Quit
        else {
            char quitChoice;

            do {
                _display << "\n*Are you sure you want to quit? (y/n)*" << std::endl;
                _input >> userInput;

                if (userInput.length() == 1) {
                    quitChoice = std::tolower(userInput.front());
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

void MenuInterface::describeViewMenu() {
    const std::unordered_set<char> menuOptions {'d', 'v', 'r'};
    std::string userInput;
    char choice;

    _display << "What would you like to do" << std::endl
             << " (d)escribe the dungeon level" << std::endl
             << " (v)iew the dungeon level" << std::endl
             << " (r)eturn to the main menu" << std::endl;
    _input >> userInput;

    //Valid input
    if (userInput.length() == 1 and isValidOption(menuOptions, std::tolower(userInput.front()))) {
        choice  = std::tolower(userInput.front());
        //Describe Dungeon
        if (choice == 'd') {
            game->describeDungeon(_display);
            explorationMenu();
        }
        //View Dungeon
        else if (choice == 'v') {
            game->displayLevel(_display);
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

void MenuInterface::explorationMenu() {
    const std::unordered_set<char> menuOptions{'d', 'r'};
    std::string userInput;
    char choice;

    _display << "What would you like to do" << std::endl
             << " (d)escribe a room" << std::endl
             << " (r)eturn to previous menu" << std::endl;
    _input >> userInput;

    //Valid input
    if (userInput.length() == 1 and isValidOption(menuOptions, std::tolower(userInput.front()))) {
        choice  = std::tolower(userInput.front());
        //Describe the room.
        if (choice == 'd') {
            int roomNumber;
            //Get Room Number.
            do {
                _display << "\nWhich room would you like to describe? (1";
                if (_numOfRooms == 1) {
                    _display << ")" << std::endl;
                } else {
                    _display << "-" << _numOfRooms << ")" << std::endl;
                }
                _input >> roomNumber;

                if (_input.fail() or not isValidRoomNumber(roomNumber)) {
                    _input.clear();
                    _input.ignore();
                    _display << "\nInvalid input option" << std::endl;

                    if (_numOfRooms == 1) {
                        _display << "Please enter 1" << std::endl;
                    } else {
                        _display << "Please enter a value between [1-" << _numOfRooms << "] " << "(inclusive)" << std::endl;
                    }

                }
            } while (_input.fail() or not isValidRoomNumber(roomNumber));

            _display << "\nRoom *" << roomNumber << "* is..." << std::endl;
            game->describeRoom(roomNumber, _display);
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
                 << "Please enter either ['d', 'r']\n" << std::endl;
        explorationMenu();
    }

}

bool MenuInterface::isValidOption(const std::unordered_set<char>& menuOptions, const char userInput) const {
    if (menuOptions.count(userInput) == 1) {
        return true;
    } else {
        return false;
    }
}

bool MenuInterface::isValidDimension(const int userInput) const {
    if (userInput > 0 and userInput < 5) {
        return true;
    } else {
        return false;
    }
}

bool MenuInterface::isValidRoomNumber(const int userInput) const {
    if (userInput < 1 or userInput > _numOfRooms) {
        return false;
    }
    return true;
}
}
