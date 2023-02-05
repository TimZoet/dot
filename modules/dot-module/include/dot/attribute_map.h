#pragma once

////////////////////////////////////////////////////////////////
// Standard includes.
////////////////////////////////////////////////////////////////

#include <ostream>
#include <string>
#include <unordered_map>

namespace dot
{
    class AttributeMap
    {
    public:
        std::unordered_map<std::string, std::string> attributes;

        AttributeMap() = default;

        AttributeMap(const AttributeMap&) = default;

        AttributeMap(AttributeMap&&) = default;

        virtual ~AttributeMap() = default;

        AttributeMap& operator=(const AttributeMap&) = default;

        AttributeMap& operator=(AttributeMap&&) = default;

        ////////////////////////////////////////////////////////////////
        // Write.
        ////////////////////////////////////////////////////////////////

        virtual void write(std::ostream& out) const;

        ////////////////////////////////////////////////////////////////
        // Getters.
        ////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////
        // Setters.
        ////////////////////////////////////////////////////////////////

        void setLabel(std::string label);

        void setShape(std::string shape);
    };
}  // namespace dot