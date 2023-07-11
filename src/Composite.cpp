#include "../include/Composite.hpp"

void Composite::add(const std::shared_ptr<Component>& component)
{
    this->children.push_back(component);
    component->setParent(std::unique_ptr<Component>(this));
}

void Composite::remove(const std::shared_ptr<Component>& component)
{
    this->children.remove(component);
    component->setParent(nullptr);
}

bool Composite::isComposite() const
{
    return true;
}

std::string Composite::operation() const
{
    std::string result;
    for (const auto& component: children)
    {
        if (component == children.back())
        {
            result += component->operation();
        }
        else
        {
            result += component->operation() + "+";
        }
    }
    return "Branch(" + result + ")";
}
