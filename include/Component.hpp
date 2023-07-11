#pragma once

#include <memory>

class Component
{
public:
    void setParent(std::unique_ptr<Component> parent);
    [[nodiscard]] const std::unique_ptr<Component>& getParent() const;
    virtual void add(const std::shared_ptr<Component>& component);
    virtual void remove(const std::shared_ptr<Component>& component);
    [[nodiscard]] virtual bool isComposite() const;
    [[nodiscard]] virtual std::string operation() const = 0;
    virtual ~Component() = default;
protected:
    std::unique_ptr<Component> parent;
};
