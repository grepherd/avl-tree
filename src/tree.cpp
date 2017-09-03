
#include "tree.hpp"

// Class constructor
// sets the data of the root node
Tree::Tree(int newData) : data(newData)
{
}

// Insert a new value into the tree
// Returns true if the insert was successful
bool Tree::insert(int newData)
{
    bool retval = false;

    if (newData < this->data)
    {
        // Insert lesser values to the left
        if (this->left == NULL)
        {
            // Reached leaf node; insert data here
            this->left = std::unique_ptr<Tree>(new Tree(newData));
            retval = true;
        }
        else
        {
            // Child node exists; keep searching
            retval = this->left->insert(newData);
        }
    }
    else if (newData > this->data)
    {
        // Insert greater values to the right
        if (this->right == NULL)
        {
            // Reached leaf node; insert data here
            this->right = std::unique_ptr<Tree>(new Tree(newData));
            retval = true;
        }
        else
        {
            // Child node exists; keep searching
            retval = this->right->insert(newData);
        }
    }
    else
    {
        // BSTs are considered sets, so unique values are not permitted
        retval = false;
    }
}

uint size_helper(Tree *node)
{
    uint leftSize;
    uint rightSize;

    if (node->left == NULL)
    {
        leftSize = 0;
    }
    else
    {
        leftSize = size_helper(node->left.get());
    }

    if (node->right == NULL)
    {
        rightSize = 0;
    }
    else
    {
        rightSize = size_helper(node->right.get());
    }

    return 1 + leftSize + rightSize;
}

uint Tree::size()
{
    return size_helper(this);
}