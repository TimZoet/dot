#include "dot/graph.h"

namespace dot
{
    Node& Graph::createNode() { return *nodes.emplace_back(std::make_unique<Node>(*this, nodes.size())); }

    Edge& Graph::createEdge(Node& from, Node& to)
    {
        return *edges.emplace_back(std::make_unique<Edge>(edges.size(), from, to));
    }

    Graph& Graph::createSubgraph(const bool isCluster)
    {
        auto& graph   = *subgraphs.emplace_back(std::make_unique<Graph>());
        graph.index   = root ? root->subgraphs.size() : subgraphs.size();
        graph.root    = root ? root : this;
        graph.parent  = this;
        graph.cluster = isCluster;
        return graph;
    }

    ////////////////////////////////////////////////////////////////
    // Write.
    ////////////////////////////////////////////////////////////////

    void Graph::write(std::ostream& out) const
    {
        if (!root)
            out << "digraph {\n";
        else if (cluster)
            out << "subgraph cluster_" << index << "{\n";
        else
            out << "subgraph {\n";

        // Write attributes.
        AttributeMap::write(out);

        // Write subgraphs.
        for (const auto& graph : subgraphs)
        {
            graph->write(out);
            out << "\n";
        }

        // Write nodes.
        for (const auto& node : nodes)
        {
            node->write(out);
            out << "\n";
        }

        // Write edges.
        for (const auto& edge : edges)
        {
            edge->write(out);
            out << "\n";
        }

        // Write closing brace.
        out << "}";
    }

    ////////////////////////////////////////////////////////////////
    // Getters and setters.
    ////////////////////////////////////////////////////////////////

    size_t Graph::getIndex() const noexcept { return index; }

    bool Graph::isCluster() const noexcept { return cluster; }

    const std::vector<NodePtr>& Graph::getNodes() const noexcept { return nodes; }

}  // namespace dot