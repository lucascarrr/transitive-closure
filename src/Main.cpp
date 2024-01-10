#include <iostream>
//#include "graph/Graph.h"
#include "node/Node.h"

int main() {
    char choice;
    std::string node_string;
    std::string relation_string;

    while (true) {
        std::cout << "Welcome:\n"
                  << "Press (1) to create new graph.\n"
                  << "Press (2) to insert new node.\n"
                  << "Press (3) to add new relation.\n"
                  << "Press (4) to print transitive closure.\n"
                  << "Press (5) to save to file.\n"
                  << "Press (6) to reset to original.\n"
                  << "Press (q) to quit." << std::endl;

        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case '1':
                std::cin.ignore();
                std::cout << "Enter nodes {Node1, Node2, Node3, NodeN}" << std::endl;
                std::getline(std::cin, node_string, '\n');
                std::cout << "Enter relations {(Node1, Node2), (Node2, Node3), (Node3, Node1)}" << std::endl;
                std::getline(std::cin, relation_string, '\n');
                std::cout << "Node String: " << node_string << " Relation String: " << relation_string << std::endl;
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
            case '6': 
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

