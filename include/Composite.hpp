#pragma once

#include <list>
#include "Component.hpp"

class Composite : public Component
{
public:
    void add(const std::shared_ptr<Component>& component) override;
    void remove(const std::shared_ptr<Component>& component) override;
    [[nodiscard]] bool isComposite() const override;
    [[nodiscard]] std::string operation() const override;

protected:
    std::list<std::shared_ptr<Component>> children;
};
