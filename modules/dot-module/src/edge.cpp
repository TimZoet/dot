#include "dot/edge.h"

////////////////////////////////////////////////////////////////
// Current target includes.
////////////////////////////////////////////////////////////////

#include "dot/node.h"

namespace dot
{
    Edge::Edge(size_t index, Node& fromNode, Node& toNode) : index(index), from(&fromNode), to(&toNode) {}

    ////////////////////////////////////////////////////////////////
    // Write.
    ////////////////////////////////////////////////////////////////

    void Edge::write(std::ostream& out) const
    {
        // Write node IDs.
        out << "    " << from->getName() << "->" << to->getName() << " ";

        // Write attributes.
        out << "[";
        AttributeMap::write(out);
        out << "]";
    }

    ////////////////////////////////////////////////////////////////
    // Getters and setters.
    ////////////////////////////////////////////////////////////////

    size_t Edge::getIndex() const noexcept { return index; }

}  // namespace dot
