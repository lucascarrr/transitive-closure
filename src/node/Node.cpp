#include "Node.h"

Node::Node() : name(""), incoming_edges(), outgoing_edges() {} 

Node::Node(const std::vector<Node*>& incoming_edges_argument,
           const std::vector<Node*>& outgoing_edges_argument,
           const std::string& name_argument)
           : name(name_argument), incoming_edges(incoming_edges_argument), outgoing_edges(outgoing_edges_argument) {} 

std::string Node::getName() const {return name; } 

void Node::setName(const std::string& name) { this->name = name; }

std::vector<Node*> Node::getIncomingEdges() const { return incoming_edges; }

std::vector<Node*> Node::getOutgoingEdges() const { return outgoing_edges; }

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

std::string Node::toString() 
{
    std::string nodeToString, temp_incoming_edges, temp_outgoing_edges; 
    
    nodeToString += "Node Name: " + name + "\n";
    nodeToString += "Incoming Edges: {" + nodeVectorToString(incoming_edges) + "}\n";
    nodeToString += "Outgoing Edges: {" + nodeVectorToString(outgoing_edges) + "}";
    
    return nodeToString;
}

std::string Node::nodeVectorToString(const std::vector<Node*>& vec) 
{
    std::string temp_string;

    for (const auto& node : vec) 
    {
        temp_string += node->getName() + " ";
    }
    return temp_string;
}

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