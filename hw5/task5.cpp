#include "structures.h"

// Высота поддерева: 0 для nullptr, иначе 1 + max(высоты детей).
int height(TreeNode* root)
{
    if (root == nullptr)
        return 0;

    return 1 + std::max(height(root->left), height(root->right));
}

// Заполняем balance_factor = height(левого) - height(правого) для каждого узла.
// Пост-обход: сначала обрабатываем детей, потом узел.
// Для BST баланс-фактор традиционно считается как разница высот поддеревьев.
void compute_balance(TreeNode* root)
{
    if (root == nullptr)
        return;

    compute_balance(root->left);
    compute_balance(root->right);

    root->balance_factor = height(root->left) - height(root->right);
}

void print_balance(TreeNode* root)
{
    if (root == nullptr)
        return;

    std::cout << "узел " << root->value
              << ": balance_factor = " << root->balance_factor << std::endl;
    print_balance(root->left);
    print_balance(root->right);
}

int main()
{
    fix_console_encoding();
    std::cout << "Задача 5: Balance factor" << std::endl;

    std::vector<int> values = {10, 5, 15, 3, 7, 12, 20, 1};
    TreeNode* root = build_bst(values);

    compute_balance(root);
    print_balance(root);

    delete_tree(root);
    return 0;
}
