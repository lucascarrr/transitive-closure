#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>
#include <tuple>
#include "../node/Node.h"

class Graph 
{
private:
    std::vector<Node*> nodes; 
    std::vector<Node*> inital_graph;
    std::vector<std::tuple<std::string>> initial_binary_relations;
    std::vector<std::tuple<std::string>> transitive_closure;

public: 
    Graph(); 
    Graph(const std::vector<std::string>& input_nodes, std::vector<std::tuple<std::string>>& input_edges);

    void addNode(Node* new_node); 
    void removeNode(std::string node_name); 

    void addEdge(const std::tuple<std::string>& new_edge); 
    void removeEdge(const std::tuple<std::string>& removed_edge); 

    /*
    returns graph to state after initial construction (if using default constructor, this is just an empty graph)
    */
    void resetGraph(); 

    /*
    toString method which returns 
    Nodes: {list of nodes}
    */
    std::string toString();

    ~Graph(); 
};

#endif