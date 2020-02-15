#include <iostream>
#include "src/lib/solution.h"

int main()
{
    std::vector<int> input = {10, 20, 2, 0, -8, -6, 41, -9, 5, 15};
    BST *tree = new BST(input);
    tree->Inorder();
    if (tree->find(20))
        std::cout << "Key(20) found in the given BST" << std::endl;
    else
        std::cout << "Key(20) wasn't found in the given BST" << std::endl;

    if (tree->find(-92))
        std::cout << "Key(-92) found in the given BST" << std::endl;
    else
        std::cout << "Key(-92) wasn't found in the given BST" << std::endl;

    if (tree->erase(20))
        std::cout << "Key(20) was erased in the given BST" << std::endl;
    else
        std::cout << "Can't delete Key(20) in the given BST" << std::endl;

    if (tree->erase(100))
        std::cout << "Key(100) was erased in the given BST" << std::endl;
    else
        std::cout << "Can't delete Key(100) in the given BST" << std::endl;

    tree->Inorder();

    return EXIT_SUCCESS;
}