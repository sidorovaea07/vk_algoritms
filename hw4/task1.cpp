#include "structures.h"

int main()
{
    std::cout << "Задача 1: Восстановление бинарного дерева" << std::endl;
    std::vector<std::optional<int>> values = {1, 2, 3, 4, 5, std::nullopt, 7};

    TreeNode* root = build_tree(values);
    std::cout << "Обход построенного дерева: ";
    print_tree(root);
    std::cout << std::endl;

    delete_tree(root);
    return 0;
}
