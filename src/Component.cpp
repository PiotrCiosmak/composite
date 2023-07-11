#include "../include/Component.hpp"

void Component::setParent(const std::shared_ptr<Component>& parent)
{
    this->parent = parent;
}

const std::shared_ptr<Component>& Component::getParent() const
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
