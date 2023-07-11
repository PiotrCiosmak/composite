#include <iostream>
#include "include/Component.hpp"
#include "include/Leaf.hpp"
#include "include/Composite.hpp"

void clientCode(const std::shared_ptr<Component>& component);
void clientCode2(const std::shared_ptr<Component>& component1, const std::shared_ptr<Component>& component2);

int main()
{
    std::shared_ptr<Component> simple = std::make_unique<Leaf>();
    std::cout << "Client: I've got a simple component:\n";

    clientCode(simple);
    std::cout << std::endl << std::endl;

    std::shared_ptr<Component> tree = std::make_unique<Composite>();
    std::unique_ptr<Component> branch1 = std::make_unique<Composite>();
    std::unique_ptr<Component> branch2 = std::make_unique<Composite>();

    std::unique_ptr<Component> leaf1 = std::make_unique<Leaf>();
    std::unique_ptr<Component> leaf2 = std::make_unique<Leaf>();
    std::unique_ptr<Component> leaf3 = std::make_unique<Leaf>();

    branch1->add(std::move(leaf1));
    branch1->add(std::move(leaf2));
    branch2->add(std::move(leaf3));

    tree->add(std::move(branch1));
    tree->add(std::move(branch2));

    std::cout << "Client: Now I've got a composite tree:\n";
    clientCode(tree);
    std::cout << "\n\n";

    std::cout << "Client: I don't need to check the components classes even when managing the tree:\n";
    clientCode2(tree, simple);
    std::cout << "\n";
}

void clientCode(const std::shared_ptr<Component>& component)
{
    std::cout << "RESULT: " << component->operation();
}

void clientCode2(const std::shared_ptr<Component>& component1, const std::shared_ptr<Component>& component2)
{
    if (component1->isComposite())
    {
        component1->add(component2);
    }
    std::cout << "RESULT: " << component1->operation();
}