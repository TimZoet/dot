#pragma once

////////////////////////////////////////////////////////////////
// Standard includes.
////////////////////////////////////////////////////////////////

#include <vector>

////////////////////////////////////////////////////////////////
// Current target includes.
////////////////////////////////////////////////////////////////

#include "dot/attribute_map.h"
#include "dot/edge.h"
#include "dot/node.h"

namespace dot
{
    class Graph;
    using GraphPtr = std::unique_ptr<Graph>;

    class Graph final : public AttributeMap
    {
    public:
        ////////////////////////////////////////////////////////////////
        // Constructors.
        ////////////////////////////////////////////////////////////////

        Graph() = default;

        Graph(const Graph&) = default;

        Graph(Graph&&) = default;

        ~Graph() override = default;

        Graph& operator=(const Graph&) = default;

        Graph& operator=(Graph&&) = default;

        Node& createNode();

        Edge& createEdge(Node& from, Node& to);

        Graph& createSubgraph(bool isCluster);

        ////////////////////////////////////////////////////////////////
        // Write.
        ////////////////////////////////////////////////////////////////

        void write(std::ostream& out) const override;

        ////////////////////////////////////////////////////////////////
        // Getters and setters.
        ////////////////////////////////////////////////////////////////

        [[nodiscard]] size_t getIndex() const noexcept;

        [[nodiscard]] bool isCluster() const noexcept;

        [[nodiscard]] const std::vector<NodePtr>& getNodes() const noexcept;

    private:
        size_t                index   = 0;
        Graph*                root    = nullptr;
        Graph*                parent  = nullptr;
        bool                  cluster = false;
        std::vector<NodePtr>  nodes;
        std::vector<EdgePtr>  edges;
        std::vector<GraphPtr> subgraphs;
    };
}  // namespace dot