
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
  protected:
    std::unique_ptr<Tree> left;
    std::unique_ptr<Tree> right;

  public:
    std::unique_ptr<int> data;

    Tree();
    Tree(int newData);

    bool insert(int data); // Add a new node to the tree (returns false on failure)
    uint size();           // Return the number of nodes in the tree
    void empty();          // Delete all the nodes in the tree
};

#ifdef UNIT_TEST

TEST_CASE("Tree Size", "[tree]")
{
    Tree test = Tree();
    CHECK(test.size() == 0);

    test.insert(5);
    CHECK(test.size() == 1);

    test.insert(3);
    test.insert(7);
    test.insert(1);
    test.insert(9);
    CHECK(test.size() == 5);

    test.empty();
    CHECK(test.size() == 0);
}

#endif

#endif