#include <iostream>

template <typename Trait>
struct Node
{
    typedef typename Trait::Type T;
    typedef Node<Trait> node;
    T dimension = Trait::Dimension;
    T *data;
    node *left = nullptr;
    node *right = nullptr;
    Node()
    {
        
    }
    Node(T *input)
    {
        data = new T[dimension];
        for (int i = 0; i < dimension; i++)
        {
            data[i] = input[i];
        }
    }
    void print()
    {
        std::cout << "(";
        for (int i = 0; i < dimension; i++)
        {
            if (i + 1 == dimension)
            {
                std::cout << data[i];
            }
            else
            {
                std::cout << data[i] << ",";
            }
        }
        std::cout << ")";
    }
};