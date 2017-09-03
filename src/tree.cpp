
#include "tree.hpp"

// Class constructor
// sets the data of the root node
Tree::Tree()
{
}

Tree::Tree(int newData) : data(std::make_unique<int>(newData))
{
}

// Insert a new value into the tree
// Returns true if the insert was successful
bool Tree::insert(int newData)
{
    bool retval = false;

    // Check for empty root node
    if (this->data == NULL)
    {
        this->data = std::make_unique<int>(newData);
    }
    else if (newData < *(this->data))
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
    else if (newData > *(this->data))
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

// Returns the number of nodes in the tree
uint Tree::size()
{
    uint leftSize;
    uint rightSize;

    // Node with no data is equivalent to no node
    if (this->data == NULL)
    {
        return 0;
    }

    if (this->left == NULL)
    {
        leftSize = 0;
    }
    else
    {
        leftSize = this->left.get()->size();
    }

    if (this->right == NULL)
    {
        rightSize = 0;
    }
    else
    {
        rightSize = (this->right.get()->size());
    }

    return 1 + leftSize + rightSize;
}

// Delete all the nodes in the tree
void Tree::empty()
{
    // Reassign root ptr
    // unique_ptr will clean up appropriately
    this->data = NULL;
}