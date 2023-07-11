#pragma once

#include "Component.hpp"

class Leaf : public Component
{
public:
    [[nodiscard]] std::string operation() const override;
};
