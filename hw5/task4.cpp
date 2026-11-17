#include "structures.h"

// K-й наименьший элемент в BST.
// Используем свойства BST: in-order обход даёт возрастающую последовательность.
// Останавливаемся, как только насчитали K элементов.
// Сложность: O(H + K), где H - высота дерева.
void in_order(TreeNode* root, int& k, int& result)
{
    if (root == nullptr || k == 0)
        return;

    in_order(root->left, k, result);
    if (k == 0)
        return;

    if (--k == 0)
        result = root->value;  // нашли K-й

    in_order(root->right, k, result);
}

int kth_smallest(TreeNode* root, int k)
{
    int result = -1;
    in_order(root, k, result);
    return result;
}

// K-й наибольший: зеркальный in-order (правый -> корень -> левый).
void reverse_in_order(TreeNode* root, int& k, int& result)
{
    if (root == nullptr || k == 0)
        return;

    reverse_in_order(root->right, k, result);
    if (k == 0)
        return;

    if (--k == 0)
        result = root->value;

    reverse_in_order(root->left, k, result);
}

int kth_largest(TreeNode* root, int k)
{
    int result = -1;
    reverse_in_order(root, k, result);
    return result;
}

int main()
{
    fix_console_encoding();
    std::cout << "Задача 4: K-ый элемент в BST" << std::endl;

    std::vector<int> values = {8, 3, 10, 1, 6, 14, 4, 7};
    TreeNode* root = build_bst(values);
    int k = 3;

    std::cout << "BST (прямой обход): ";
    print_tree(root);
    std::cout << "\nK = " << k << std::endl;

    std::cout << k << "-й наименьший: " << kth_smallest(root, k) << std::endl;
    std::cout << k << "-й наибольший: " << kth_largest(root, k) << std::endl;

    delete_tree(root);
    return 0;
}
