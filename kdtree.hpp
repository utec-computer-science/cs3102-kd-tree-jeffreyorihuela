#ifndef KDTREE_HPP
#define KDTREE_HPP

#include "node.hpp"
#include <iostream>

struct Point2D
{
    using Type = int;
    static Type const Dimension = 2;
};

template <typename Trait>
class KdTree
{
    typedef typename Trait::Type T;
    typedef typename ::Node<Trait> node;
    node *root = nullptr;
    int height = 0;
    int order = Trait::Dimension;

public:
    void insert(T *input)
    {
        node *newNode = new node(input);
        if (!root)
        {
            this->root = newNode;
        }
        else
        {
            insert_(newNode, root, 0);
        }
    }

    void search(T *input)
    {
        node *wanted = new node(input);
        bool found = search_(wanted, root, 0);
        if (found)
        {
            std::cout << "the kdtree has found it\n";
        }
        else
        {
            std::cout << "the kdtree has not found it\n";
        }
    }

    void print()
    {
        for (int i = 0; i <= height; i++)
        {
            printLevel(root, i);
            std::cout << '\n';
        }
    }

private:
    void insert_(node *newNode, node *currentNode, int level)
    {
        if (level + 1 > height)
        {
            this->height = this->height + 1;
        }
        int index = level % order;
        if (currentNode->data[index] < newNode->data[index])
        {
            if (currentNode->right)
                insert_(newNode, currentNode->right, level + 1);
            else
                currentNode->right = newNode;
        }
        else
        {
            if (currentNode->left)
                insert_(newNode, currentNode->left, level + 1);
            else
                currentNode->left = newNode;
        }
    }

    bool search_(node *wanted, node *root, int level)
    {
        if (!root)
        {
            return false;
        }
        else
        {
            if (root->compare(wanted))
                return true;
            else
            {
                int index = level % order;
                if (root->data[index] < wanted->data[index])
                {
                    search_(wanted, root->right, level + 1);
                }
                else
                {
                    search_(wanted, root->left, level + 1);
                }
            }
        }
    }

    void printLevel(node *ptr, int level)
    {
        if (!ptr)
            return;
        if (level == 0)
            ptr->print();
        else if (level > 0)
        {
            printLevel(ptr->left, level - 1);
            printLevel(ptr->right, level - 1);
        }
    }
};

#endif