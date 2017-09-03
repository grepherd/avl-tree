
#ifndef TREE_HPP
#define TREE_HPP

#include <memory>
#include <iostream>

//Only include if cmake enabled unit testing on this target
#ifdef UNIT_TEST
#include "catch.hpp"
#endif

class Tree
{

  public:
    // These are only public for development convenience!
    int data;
    std::unique_ptr<Tree> left;
    std::unique_ptr<Tree> right;

    Tree(int data);
    bool insert(int data);
    uint size();
};

#ifdef UNIT_TEST
TEST_CASE("Tree Size", "[tree]")
{
    Tree test = Tree(5);
    CHECK(test.size() == 1);

    test.insert(3);
    test.insert(7);
    test.insert(1);
    test.insert(9);
    CHECK(test.size() == 5);
}

#endif

#endif