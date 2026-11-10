#include "structures.h"

bool is_mirror(TreeNode* left, TreeNode* right)
{
    if (left == nullptr && right == nullptr)
        return true;

    if (left == nullptr || right == nullptr)
        return false;

    return left->value == right->value &&
           is_mirror(left->left, right->right) &&
           is_mirror(left->right, right->left);
}

bool is_symmetric(TreeNode* root)
{
    if (root == nullptr)
        return true;

    return is_mirror(root->left, root->right);
}

int main()
{
    std::cout << "Задача 2: Симметричное бинарное дерево" << std::endl;
    std::vector<std::optional<int>> values = {1, 2, 2, 3, 4, 4, 3};
    TreeNode* root = build_tree(values);

    if (is_symmetric(root))
        std::cout << "Дерево симметрично" << std::endl;
    else
        std::cout << "Дерево несимметрично" << std::endl;

    delete_tree(root);
    return 0;
}
