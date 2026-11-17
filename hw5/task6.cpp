#include "structures.h"

// Зеркальное отражение дерева: меняем местами левое и правое поддеревья
// каждого узла и рекурсивно отражаем сами поддеревья.
// Корректность: для каждого узла поддеревья меняются местами на всех уровнях,
// что и есть зеркальное отображение. Сложность: O(N), память O(H) на рекурсию.
void mirror(TreeNode* root)
{
    if (root == nullptr)
        return;

    std::swap(root->left, root->right);
    mirror(root->left);
    mirror(root->right);
}

int main()
{
    fix_console_encoding();
    std::cout << "Задача 6: Преобразование в зеркальное дерево" << std::endl;

    std::vector<std::optional<int>> values = {1, 2, 3, 4, 5, 6, 7};
    TreeNode* root = build_tree(values);

    std::cout << "До зеркала: ";
    print_tree(root);
    std::cout << std::endl;

    mirror(root);

    std::cout << "После зеркала: ";
    print_tree(root);
    std::cout << std::endl;

    delete_tree(root);
    return 0;
}

