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
    class Graph;

    class Node final : public AttributeMap
    {
    public:
        Node() = delete;

        Node(const Node&) = default;

        Node(Node&&) = default;

        Node(Graph& parent, size_t index);

        ~Node() override = default;

        Node& operator=(const Node&) = default;

        Node& operator=(Node&&) = default;

        ////////////////////////////////////////////////////////////////
        // Write.
        ////////////////////////////////////////////////////////////////

        void write(std::ostream& out) const override;

        ////////////////////////////////////////////////////////////////
        // Getters and setters.
        ////////////////////////////////////////////////////////////////

        [[nodiscard]] size_t getIndex() const noexcept;

        [[nodiscard]] std::string getName() const;

    private:
        Graph* graph = nullptr;
        size_t index;
    };

    using NodePtr = std::unique_ptr<Node>;
}  // namespace dot