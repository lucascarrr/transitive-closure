#include "Graph.h"

Graph::Graph() : nodes(), inital_graph(), initial_relations(), transitive_closure() {}

Graph::Graph(const std::vector<std::string>& input_nodes, const std::vector<std::tuple<std::string, std::string>>& input_relations)
{
    for (const auto& node_name : input_nodes) {
        nodes[node_name] = new Node({}, {}, node_name);
    }

        // Step 2: Establish connections between nodes
    for (const auto& relation : input_relations) {
        const std::string& source_name = std::get<0>(relation);
        const std::string& target_name = std::get<1>(relation);

        // Check if the names are valid (exist in the nodes map)
        if (nodes.find(source_name) != nodes.end() && nodes.find(target_name) != nodes.end()) {

            nodes[source_name]->addOutgoingEdge(nodes[target_name]);
            nodes[target_name]->addIncomingEdge(nodes[source_name]);
        }
        // Handle invalid node names if needed
        else {
            std::cerr << "Error: Invalid node names in relation. Source node: " << source_name
                      << ", Target node: " << target_name << std::endl;

        }
    }
}


// /*
// Copy Constructor
// */

// Graph::Graph(const Graph& other) 
// {
//     for (std::unordered_map<std::string,Node>::iterator it=other.getNodes().begin(); it!=other.getNodes().end(); ++it)
//     {

//     }
  
// }

// void Graph::addNode(Node new_node)
// {
//     if (nodes.count(new_node.getName()))
//     {
//         std::cerr << "ERROR: Node " << new_node.getName() << " already exists. Operation aborted!" << std::endl;
//     }
//     else 
//     {
//         nodes[new_node.getName()] = new_node
//     }
// }

std::unordered_map<std::string, Node*> Graph::getNodes() const
{
    return nodes;
}

std::string Graph::toString()
{
    std::string map_as_string;
    for (const auto& pair : nodes) 
    {
    map_as_string += pair.second->toString()+ "\n";
    }
    return map_as_string;
}