#include <iostream>
#include "graph/Graph.h"

int main() {
    char choice;

    while (true) {
        std::cout << "Welcome:\n"
                  << "Press (1) to insert new node.\n"
                  << "Press (2) to add new relation.\n"
                  << "Press (3) to print transitive closure.\n"
                  << "Press (4) to save.\n"
                  << "Press (5) to reset.\n"
                  << "Press (q) to quit." << std::endl;

        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case '1':
                std::cout << "Enter node name" << choice << std::endl;
                break;
            case '2':
                std::cout << "You entered " << choice << std::endl;
                break;
            case '3':
                std::cout << "You entered " << choice << std::endl;
                break;
            case '4':
                std::cout << "You entered " << choice << std::endl;
                break;
            case '5':
                std::cout << "You entered " << choice << std::endl;
                break;
            case 'q':
                std::cout << "Quitting program." << std::endl;
                return 0; // Exit the program
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    }

    return 0;
}
