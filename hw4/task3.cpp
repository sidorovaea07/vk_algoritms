#include "structures.h"

int min_depth(TreeNode* root)
{
    if (root == nullptr)
        return 0;

    std::queue<TreeNode*> nodes;
    nodes.push(root);
    int depth = 1;

    while (!nodes.empty())
    {
        int level_size = nodes.size();

        for (int i = 0; i < level_size; ++i)
        {
            TreeNode* current = nodes.front();
            nodes.pop();

            if (current->left == nullptr && current->right == nullptr)
                return depth;

            if (current->left != nullptr)
                nodes.push(current->left);

            if (current->right != nullptr)
                nodes.push(current->right);
        }
        depth++;
    }

    return depth;
}

int main()
{
    std::cout << "Задача 3: Минимальная глубина бинарного дерева" << std::endl;
    std::vector<std::optional<int>> values = {1, 2, 3, 4, std::nullopt, std::nullopt, 5};
    TreeNode* root = build_tree(values);

    std::cout << "Минимальная глубина: " << min_depth(root) << std::endl;

    delete_tree(root);
    return 0;
}
