#include "Node.h"
#include <iostream>
/*
Default Constructor
*/
Node::Node() : name(""), incoming_edges(), outgoing_edges() {} 

/*
Argument Constructor
*/
Node::Node(const std::vector<Node*> incoming_edges_argument,
           const std::vector<Node*> outgoing_edges_argument,
           const std::string& name_argument)
           : name(name_argument), incoming_edges(incoming_edges_argument), outgoing_edges(outgoing_edges_argument) {} 

/*
Copy Constructor (Deep Copy)
*/
Node::Node(const Node& other)
    : name(other.getName()) {
    
    // Deep copy of incoming_edges
    for (const Node* incoming_edge : other.getIncomingEdges()) {
        Node* new_node = new Node(*incoming_edge);
        incoming_edges.push_back(new_node);
    }

    // Deep copy of outgoing_edges
    for (const Node* outgoing_edge : other.getOutgoingEdges()) {
        Node* new_node = new Node(*outgoing_edge);
        outgoing_edges.push_back(new_node);
    }
}

/*
Move Constructor
*/
Node::Node(Node&& other)
    : name(std::move(other.name)),
      incoming_edges(std::move(other.incoming_edges)),
      outgoing_edges(std::move(other.outgoing_edges)) {
    other.name = "";  
 }

/*
Copy Assignment Operator
*/
Node& Node::operator=(const Node& other) {
    if (this != &other) {
        for (Node* incoming_edge : incoming_edges) {
            delete incoming_edge;
        }
        incoming_edges.clear();

        for (Node* outgoing_edge : outgoing_edges) {
            delete outgoing_edge;
        }
        outgoing_edges.clear();
        name = other.name;

        // Deep copy of incoming_edges
        for (const Node* incoming_edge : other.incoming_edges) {
            Node* new_node = new Node(*incoming_edge);
            incoming_edges.push_back(new_node);
        }

        // Deep copy of outgoing_edges
        for (const Node* outgoing_edge : other.outgoing_edges) {
            Node* new_node = new Node(*outgoing_edge);
            outgoing_edges.push_back(new_node);
        }
    }
    return *this;
}

/*
 Move Assignment Operator 
*/
// Move assignment operator
Node& Node::operator=(Node&& other) {
    if (this != &other) {
        name = std::move(other.name);
        incoming_edges = std::move(other.incoming_edges);
        outgoing_edges = std::move(other.outgoing_edges);

        other.name = "";  
    }
    return *this;
}

/*
Getter Method
*/
std::string Node::getName() const {return name; } 

std::vector<Node*> Node::getIncomingEdges() const { return incoming_edges; }

std::vector<Node*> Node::getOutgoingEdges() const { return outgoing_edges; }

/*
Setter Methods
*/
void Node::setName(const std::string& name) { this->name = name; }

void Node::addIncomingEdge(Node* node) { incoming_edges.push_back(node); }

void Node::addOutgoingEdge(Node* node) { outgoing_edges.push_back(node); }

void Node::deleteIncomingEdge(const std::string& name_argument) 
{ 
    for (std::vector<Node*>::iterator it = incoming_edges.begin(); it != incoming_edges.end();)
    {
        if ((*it)->getName() == name_argument) {
            it = incoming_edges.erase(it); // erase and get the iterator to the next element
        } else {
            ++it; // move to the next element
        }
    }
}

void Node::deleteOutgoingEdge(const std::string& name_argument) 
{
    for (std::vector<Node*>::iterator it = outgoing_edges.begin(); it != outgoing_edges.end();)
    {
        if ((*it)->getName() == name_argument) {
            it = incoming_edges.erase(it); // erase and get the iterator to the next element
        } else {
            ++it; 
        }
    }
}

/*
To String Methods
*/
std::string Node::toString() const
{
    std::string nodeToString, temp_incoming_edges, temp_outgoing_edges; 
    
    nodeToString += "Node Name: " + name + "\n";
    nodeToString += "Incoming Edges: {" + nodeVectorToString(incoming_edges) + "}\n";
    nodeToString += "Outgoing Edges: {" + nodeVectorToString(outgoing_edges) + "}\n";
    
    return nodeToString;
}

std::string Node::nodeVectorToString(const std::vector<Node*>& vec) const
{
    std::string temp_string;

    for (const auto& node : vec) 
    {
        temp_string += node->getName() + " ";
    }
    return temp_string;
}

/*
Destructor
*/
Node::~Node() 
{   
    // Deleting outgoing edges of this node from incoming nodes (memory safety)
    for (auto it = incoming_edges.begin(); it != incoming_edges.end();)
    {
        (*it)->deleteOutgoingEdge(this->name);
        it = incoming_edges.erase(it);
    }

    // Deleting incoming edges of this node from outgoing nodes (memory safety)
    for (auto it = outgoing_edges.begin(); it != outgoing_edges.end();)
    {
        (*it)->deleteIncomingEdge(this->name);
        it = outgoing_edges.erase(it);
    }
}