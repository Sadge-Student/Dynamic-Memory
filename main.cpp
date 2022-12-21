// Assignment-Dynamic-Memory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <algorithm>
#include <iostream>
#include <conio.h>
#include "deck.h"

bool invalid_option_main_menu = false;
Deck* deck = new Deck();
bool displayed_help = false;
std::vector<Card>* dealt_cards;

// enum of selectable options within main menu
enum class SELECTED { EXIT, PLAY, INSTRUCTIONS, CREDITS };

void DisplayMenu();
void Instructions();
void Start();
void Initialize();

int main()
{
    DisplayMenu();
}

void DisplayMenu()
{
    // declare and assign local variables
    int num = -1;
    SELECTED option;
    displayed_help = false;
    //Stay in loop unless exited
    do
    {
        system("CLS");

        if (invalid_option_main_menu)
        {
            std::cout << "Invalid Option!\n" << std::endl;
        }

        // take in option and make sure its valid
        std::cout << "0) Exit\n1) Play\n2) Instructions\n3) Credits" << std::endl;
        std::cout << std::endl;
        std::cout << "Select an option: ";

        std::cin >> num;

        option = static_cast<SELECTED>(num);

        //Run specified action based on user input
        switch (option)
        {
        case SELECTED::PLAY:
            Initialize();
            Start();
            invalid_option_main_menu = false;
            break;
        case SELECTED::INSTRUCTIONS:
            Instructions(); // displays instructions
            invalid_option_main_menu = false;
            break;
        case SELECTED::CREDITS:
            // display credits
            system("CLS");

            std::cout << "Created by Aaron Delaney" << std::endl;
            std::cout << "\nPress any key to return to main menu" << std::endl;
            _getch();
            invalid_option_main_menu = false;
            break;
        default:
            invalid_option_main_menu = true;
            num = -1;

            // resets cin input buffer required if entering invalid characters into an int
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            DisplayMenu();
            break;
        }
    } while (option != SELECTED::EXIT);
}

void Instructions()
{
    system("CLS");
    std::cout << "Write a C++ programme that will create a deck of playing cards.  Your programme should:" << std::endl;
    std::cout << std::endl;
    std::cout << "1). Contain two classes, a Card class and a Deck class," << std::endl;
    std::cout << "2). Demonstrate composition," << std::endl;
    std::cout << "3). The card class should hold the card suit and the card value as private data members," << std::endl;
    std::cout << "4). The deck class should store objects on the heap, namely 52 instantiated cards," << std::endl;
    std::cout << "5). The deck class should use an STL container to organise your cards," << std::endl;
    std::cout << "6). A player should be able to request a new deck of cards, have the cards shuffled, and ask for a user-defined number of cards to be dealt to the player," << std::endl;
    std::cout << "7). The programme should be free from memory leaks, so create a custom copy constructor and a custom destructor for your deck class," << std::endl;
    std::cout << "8). Demonstrate your knowledge of operator overloading by overloading an operator in the deck class," << std::endl;
    std::cout << "9). Use separate .h and .cpp files for each of your classes," << std::endl;
    std::cout << "10). Use a persistent game loop" << std::endl;
    std::cout << "11). Output instructions and options to the player." << std::endl;
    std::cout << std::endl;
    std::cout << "\nPress any key to return to main menu" << std::endl;
    _getch();
}

void Start()
{
    system("CLS");
    bool running = true;
    while (running) {
        std::string command;

        if (!displayed_help)
        {
            std::cout << " help - Show this help message." << std::endl;
            std::cout << " shuffle - Shuffle the deck." << std::endl;
            std::cout << " deal - Deal x about of cards." << std::endl;
            std::cout << " new - Retrieve a new deck." << std::endl;
            std::cout << " display deck - Displays a list of all the cards in the deck." << std::endl;
            std::cout << " display hand - Displays a list of all cards in players hand." << std::endl;
            std::cout << " clear - Clears the terminal." << std::endl;
            std::cout << " quit - quit to main menu." << std::endl;
            std::cout << "" << std::endl;
            displayed_help = true;
        }

        std::cout << "Enter Command: ";
        std::getline(std::cin >> std::ws, command);
        std::transform(command.begin(), command.end(), command.begin(), std::tolower);

        if (command == "help")
        {
            std::cout << " help - Show this help message." << std::endl;
            std::cout << " shuffle - Shuffle the deck." << std::endl;
            std::cout << " deal - Deal x about of cards." << std::endl;
            std::cout << " new - Retrieve a new deck." << std::endl;
            std::cout << " display deck - Displays a list of all the cards in the deck." << std::endl;
            std::cout << " display hand - Displays a list of all cards in players hand." << std::endl;
            std::cout << " clear - Clears the terminal." << std::endl;
            std::cout << " quit - quit to main menu." << std::endl;
            std::cout << "" << std::endl;
        }
        else if (command == "shuffle")
        {
            deck->Shuffle();
            std::cout << "Deck Shuffled!" << std::endl;
        }
        else if (command == "deal")
        {
            std::cout << "Enter the number of cards you want to be dealt: ";
            int num_of_cards_to_deal = 0;
            while (true) {
                std::cin >> num_of_cards_to_deal;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input.  Try again: ";
                }
                else if (num_of_cards_to_deal < 1 || num_of_cards_to_deal > 52) {
                    std::cout << "The number of cards to deal must be between 1 and 52. Try again: ";
                }
                else {
                    break;
                }
            }
            dealt_cards = new std::vector<Card>(deck->Deal(num_of_cards_to_deal));
            std::cout << dealt_cards->size() << " cards dealt" << std::endl;
        }
        else if (command == "new")
        {
            delete deck;
            deck = new Deck();
            std::cout << "New deck received" << std::endl;

            delete dealt_cards;
            dealt_cards = nullptr;
            std::cout << "Dealt cards removed" << std::endl;
        }
        else if (command == "display deck")
        {
            if (deck->GetDeck().empty())
            {
                std::cout << "You dealt all the cards in the deck" << std::endl;
            }
            else
            {
                std::cout << *deck << std::endl;
            }
        }
        else if (command == "display hand")
        {
            if (dealt_cards != nullptr)
            {
                for (const auto& card : *dealt_cards) {
                    std::cout << card << std::endl;
                }
            }
            else
            {
                std::cout << "You haven't dealt any cards yet." << std::endl;
            }
        }
        else if (command == "clear")
        {
            system("CLS");
        }
        else if (command == "quit")
        {
            running = false;
        }
        else
        {
            std::cout << "Invalid Command! (Type 'help' for a list of commands)" << std::endl;
        }
        std::cout << std::endl;
    }
}

void Initialize()
{
    displayed_help = false;
    delete deck;
    deck = new Deck();

    delete dealt_cards;
    dealt_cards = nullptr;
}
