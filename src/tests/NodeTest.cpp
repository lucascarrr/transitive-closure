#include "../node/Node.h"
#include <iostream>

// Test class for Node
class NodeTest {
public:
    // Function to run all the tests
    void runTests() {
        testDefaultConstructor();
        testNormalConstructor();
        testToString();
        testIncomingEdge();
        testOutgoingEdge();
    }

private:
    // Helper function to check if two vectors of Node pointers are equal
    bool areEqual(const std::vector<Node*>& vec1, const std::vector<Node*>& vec2) const {
        if (vec1.size() != vec2.size()) {
            return false;
        }

        for (size_t i = 0; i < vec1.size(); ++i) {
            if (vec1[i]->getName() != vec2[i]->getName()) {
                return false;
            }
        }
        return true;
    }

    // Helper function to print test result
    void printResult(bool result, const std::string& testName) const 
    {
        std::cout << (result ? "PASS" : "FAIL") << " - " << testName << std::endl;
    }

    // Test cases
    void testDefaultConstructor() 
    {
        Node node;
        printResult(node.getName() == "" && node.getIncomingEdges().empty() && node.getOutgoingEdges().empty(), "Default Constructor");
    }

    void testNormalConstructor()
    {
        std::vector<Node*> incoming_edges; 
        std::vector<Node*> outgoing_edges;

        Node* node = new Node(incoming_edges, outgoing_edges, "Test User");
        printResult(node->getName() == "Test User" && node->getIncomingEdges().empty() && node->getOutgoingEdges().empty(), "Normal Constructor");
    }

    void testToString()
    {
        std::vector<Node*> incoming_edges; 
        std::vector<Node*> outgoing_edges;

        Node* node = new Node(incoming_edges, outgoing_edges, "Test User");
        
        printResult(node->toString() == "Node Name: Test User\nIncoming Edges: {}\nOutgoing Edges: {}", "toString Test");
    }

    void testIncomingEdge() 
    {
        std::vector<Node*> incoming_edges; 
        std::vector<Node*> outgoing_edges;

        Node* node = new Node(incoming_edges, outgoing_edges, "Test User");
        Node* node2 = new Node(incoming_edges, outgoing_edges, "Test User 2");
        
        node->addIncomingEdge(node2);
        printResult(node->getIncomingEdges()[0]->getName() == "Test User 2", "Test Incoming Edges");
    }

    void testOutgoingEdge() 
    {
        std::vector<Node*> incoming_edges; 
        std::vector<Node*> outgoing_edges;

        Node* node = new Node(incoming_edges, outgoing_edges, "Test User");
        Node* node2 = new Node(incoming_edges, outgoing_edges, "Test User 2");
        
        node->addOutgoingEdge(node2);
        printResult(node->getOutgoingEdges()[0]->getName() == "Test User 2", "Test Outgoing Edges");
    }
};

int main() {
    NodeTest nodeTest;
    nodeTest.runTests();

    return 0;
}
