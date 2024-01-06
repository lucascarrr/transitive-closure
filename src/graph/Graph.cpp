#include "Graph.h"

Graph::Graph() : nodes(), inital_graph(), initial_binary_relations(), transitive_closure() {}

Graph::Graph(const std::vector<std::string>& input_nodes, const std::vector<std::tuple<std::string>>& input_edges)
{
    // construct graph with node names and relationships 

}

void Graph::addNode(Node* new_node)
{
    nodes.push_back(new_node);
}

