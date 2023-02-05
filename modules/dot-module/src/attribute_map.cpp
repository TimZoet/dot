#include "dot/attribute_map.h"

namespace dot
{
    ////////////////////////////////////////////////////////////////
    // Write.
    ////////////////////////////////////////////////////////////////

    void AttributeMap::write(std::ostream& out) const
    {
        for (const auto& [name, value] : attributes) { out << name << "=\"" << value << "\""; }
    }

    ////////////////////////////////////////////////////////////////
    // Getters.
    ////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////
    // Setters.
    ////////////////////////////////////////////////////////////////

    void AttributeMap::setLabel(std::string label) { attributes["label"] = std::move(label); }

    void AttributeMap::setShape(std::string shape) { attributes["shape"] = std::move(shape); }
}  // namespace dot