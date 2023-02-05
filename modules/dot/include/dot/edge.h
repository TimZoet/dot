#pragma once

////////////////////////////////////////////////////////////////
// Standard includes.
////////////////////////////////////////////////////////////////

#include <memory>

////////////////////////////////////////////////////////////////
// Current target includes.
////////////////////////////////////////////////////////////////

#include "dot/attribute_map.h"

namespace dot
{
    class Node;

    class Edge final : public AttributeMap
    {
    public:
        Edge() = delete;

        Edge(const Edge&) = default;

        Edge(Edge&&) = default;

        Edge(size_t index, Node& fromNode, Node& toNode);

        ~Edge() override = default;

        Edge& operator=(const Edge&) = default;

        Edge& operator=(Edge&&) = default;

        ////////////////////////////////////////////////////////////////
        // Write.
        ////////////////////////////////////////////////////////////////

        void write(std::ostream& out) const override;

        ////////////////////////////////////////////////////////////////
        // Getters and setters.
        ////////////////////////////////////////////////////////////////

        [[nodiscard]] size_t getIndex() const noexcept;

    private:
        size_t index;
        Node* from=nullptr;
        Node* to=nullptr;
    };

    using EdgePtr = std::unique_ptr<Edge>;
}  // namespace dot