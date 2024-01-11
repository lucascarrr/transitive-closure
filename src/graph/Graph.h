#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include <iostream>
#include "../node/Node.h"

class Graph 
{
private:
    std::unordered_map<std::string, Node * > nodes;
    std::vector<Node*> inital_graph;
    std::vector<std::tuple<std::string>> initial_relations;
    std::vector<std::tuple<std::string>> transitive_closure;

public: 
    Graph(); 
    Graph(const std::vector<std::string>& input_nodes, const std::vector<std::tuple<std::string, std::string>>& input_relations);

    // /*
    // Copy Constructor
    // */
    // Graph(const Graph& other);

    // /*
    // Move Constructor
    // */
    // Graph(Graph&& other);

    /*
    Copy Assignment Operator
    */
    // Graph operator=(const Graph& other);

    // /*
    // Move Assignment Operator
    // */
    // Graph operator=(Graph&& other);

    // void addNode(Node new_node); 
    // void removeNode(const std::string& node_name); 

    // void addEdge(const std::tuple<std::string>& new_edge); 
    // void removeEdge(const std::tuple<std::string>& removed_edge); 

    std::unordered_map<std::string, Node*> getNodes() const;  
    // std::vector<Node>* getInitialGraph();
    // std::vector<std::tuple<std::string>> getInitialBinaryRelations();

    /*
    returns graph to state after initial construction (if using default constructor, this is just an empty graph)
    */
    //void resetGraph(); 

    /*
    toString method which returns adjacency matrix of the graph
    */
    std::string toString();

    //~Graph(); 
};

#endif