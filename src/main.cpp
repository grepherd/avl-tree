
#include <iostream>

#include "tree.hpp"

int main()
{
    Tree test = Tree(5);
    test.insert(4);
    test.insert(6);
    test.insert(7);

    std::cout << test.size() << std::endl;

    return 0;
}