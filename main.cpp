#include <iostream>
#include "include/Component.hpp"
#include "include/Leaf.hpp"
#include "include/Composite.hpp"

void clientCode(const std::shared_ptr<Component>& component);
void clientCode2(const std::shared_ptr<Component>& component1,
                 const std::shared_ptr<Component>& component2);

int main()
{
    std::shared_ptr<Component> simple = std::make_shared<Leaf>();
    std::cout << "Client: I've got a simple component:" << std::endl;

    clientCode(simple);
    std::cout << std::endl << std::endl;

    std::shared_ptr<Component> tree = std::make_shared<Composite>();
    std::shared_ptr<Component> branch1 = std::make_shared<Composite>();
    std::shared_ptr<Component> branch2 = std::make_shared<Composite>();

    std::shared_ptr<Component> leaf1 = std::make_shared<Leaf>();
    std::shared_ptr<Component> leaf2 = std::make_shared<Leaf>();
    std::shared_ptr<Component> leaf3 = std::make_shared<Leaf>();

    branch1->add(leaf1);
    branch1->add(leaf2);
    branch2->add(leaf3);

    tree->add(branch1);
    tree->add(branch2);

    std::cout << "Client: Now I've got a composite tree:" << std::endl;
    clientCode(tree);
    std::cout << std::endl << std::endl;

    std::cout << "Client: I don't need to check the components classes even when managing the tree:"
              << std::endl;
    clientCode2(tree, simple);
}

void clientCode(const std::shared_ptr<Component>& component)
{
    std::cout << "RESULT: " << component->operation();
}

void clientCode2(const std::shared_ptr<Component>& component1,
                 const std::shared_ptr<Component>& component2)
{
    if (component1->isComposite())
    {
        component1->add(component2);
    }
    std::cout << "RESULT: " << component1->operation();
}