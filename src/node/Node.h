#ifndef NODE_H
#define NODE_H

#include <vector>
#include <string>

class Node 
{
private: 
    std::vector<Node*> incoming_edges; 
    std::vector<Node*> outgoing_edges;
    std::string name;

    /*
    for a vector (incoming or outgoing edges), this method will get the Node.name of each element in that vector, concatenated into a string
    */
    std::string nodeVectorToString(const std::vector<Node*>& input_vector) const; 

public: 
    Node(); 
    Node(const std::vector<Node*>& incoming_edges_argument,
         const std::vector<Node*>& outgoing_edges_argument,
         const std::string& name_argument);

    Node(const Node& other);
    Node(Node&& other); 

    Node& operator=(const Node& other);
    Node& operator=(Node&& other);

    std::string getName() const;
    void setName(const std::string& name);

    std::vector<Node*> getIncomingEdges() const;
    std::vector<Node*> getOutgoingEdges() const;

    void addIncomingEdge(Node* node);
    void addOutgoingEdge(Node* node);

    void deleteIncomingEdge(const std::string& name); 
    void deleteOutgoingEdge(const std::string& name);

    // /*
    // toString method for a node. Will print:
    //     Node Name: <name of node> 
    //     Incoming Edges: {i_e1, i_e2, i_e3}
    //     Outgoing Edges: {o_e1, o_e2}
    // */
    std::string toString() const;

    ~Node(); 
};

#endif

