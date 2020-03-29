#include "kdtree.hpp"

int main()
{
    KdTree<Point2D> kdTree;
    int a[] = {2, 3};
    kdTree.insert(a);
    int b[] = {5, 4};
    kdTree.insert(b);
    int c[] = {9, 6};
    kdTree.insert(c);
    int d[] = {4, 7};
    kdTree.insert(d);
    int e[] = {8, 1};
    kdTree.insert(e);
    int f[] = {7, 2};
    kdTree.insert(f);

    kdTree.print();
}