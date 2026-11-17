#include "structures.h"

// Проверка полноты бинарного дерева через BFS.
// Идея: при обходе по уровням после первого встреченного "пустого"
// (отсутствующего) потомка не должно быть ни одного реального узла.
bool is_complete(TreeNode* root)
{
    if (root == nullptr)
        return true;

    std::queue<TreeNode*> nodes;
    nodes.push(root);
    bool seen_null = false;  // встретили ли уже узел с недостающим потомком

    while (!nodes.empty())
    {
        TreeNode* current = nodes.front();
        nodes.pop();

        if (current == nullptr)
        {
            seen_null = true;  // с этого места узлы должны отсутствовать
            continue;
        }

        if (seen_null)
            return false;  // реальный узел после пустого -> не полное

        nodes.push(current->left);
        nodes.push(current->right);
    }

    return true;
}

int main()
{
    fix_console_encoding();
    std::cout << "Задача 1: Полное бинарное дерево" << std::endl;

    // Полное дерево: все уровни заполнены, кроме последнего (слева направо)
    std::vector<std::optional<int>> complete_values = {1, 2, 3, 4, 5, 6};
    TreeNode* complete = build_tree(complete_values);
    std::cout << "Дерево {1,2,3,4,5,6}: "
              << (is_complete(complete) ? "полное" : "не полное") << std::endl;
    delete_tree(complete);

    // Не полное: узел 3 имеет правого потомка, но нет левого (6 без 7)
    std::vector<std::optional<int>> broken_values = {1, 2, 3, 4, 5, std::nullopt, 7};
    TreeNode* broken = build_tree(broken_values);
    std::cout << "Дерево {1,2,3,4,5,null,7}: "
              << (is_complete(broken) ? "полное" : "не полное") << std::endl;
    delete_tree(broken);

    return 0;
}
