#include "../include/Component.hpp"

void Component::setParent(std::unique_ptr<Component> parent)
{
    this->parent = std::move(parent);
}

const std::unique_ptr<Component>& Component::getParent() const
{
    return parent;
}

void Component::add(const std::shared_ptr<Component>& component)
{

}

void Component::remove(const std::shared_ptr<Component>& component)
{

}

bool Component::isComposite() const
{
    return false;
}
