#include "structures.h"

bool are_identical(TreeNode* first, TreeNode* second)
{
    if (first == nullptr && second == nullptr)
        return true;

    if (first == nullptr || second == nullptr)
        return false;

    return first->value == second->value &&
           are_identical(first->left, second->left) &&
           are_identical(first->right, second->right);
}

int main()
{
    std::cout << "Задача 5: Сравнение двух бинарных деревьев" << std::endl;
    std::vector<std::optional<int>> first_values = {1, 2, 3, 4, 5};
    std::vector<std::optional<int>> second_values = {1, 2, 3, 4, 5};

    TreeNode* first = build_tree(first_values);
    TreeNode* second = build_tree(second_values);

    if (are_identical(first, second))
        std::cout << "Деревья одинаковые" << std::endl;
    else
        std::cout << "Деревья разные" << std::endl;

    delete_tree(first);
    delete_tree(second);
    return 0;
}
