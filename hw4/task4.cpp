#include "structures.h"

long long min_max_product(TreeNode* root)
{
    if (root == nullptr)
        return 0;

    TreeNode* minimum = root;
    TreeNode* maximum = root;

    while (minimum->left != nullptr)
        minimum = minimum->left;

    while (maximum->right != nullptr)
        maximum = maximum->right;

    return static_cast<long long>(minimum->value) * maximum->value;
}

int main()
{
    std::cout << "Задача 4: Произведение минимума и максимума в BST" << std::endl;
    std::vector<std::optional<int>> values = {8, 3, 10, 1, 6, std::nullopt, 14, std::nullopt, std::nullopt, 4, 7};
    TreeNode* root = build_tree(values);

    std::cout << "Произведение: " << min_max_product(root) << std::endl;

    delete_tree(root);
    return 0;
}
