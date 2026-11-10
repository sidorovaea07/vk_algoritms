#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <iostream>
#include <optional>
#include <queue>
#include <vector>

struct TreeNode
{
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

static TreeNode* build_tree(const std::vector<std::optional<int>>& values)
{
    if (values.empty() || !values[0].has_value())
        return nullptr;

    TreeNode* root = new TreeNode(*values[0]);
    std::queue<TreeNode*> nodes;
    nodes.push(root);
    size_t index = 1;

    while (!nodes.empty() && index < values.size())
    {
        TreeNode* current = nodes.front();
        nodes.pop();

        if (values[index].has_value())
        {
            current->left = new TreeNode(*values[index]);
            nodes.push(current->left);
        }
        index++;

        if (index < values.size() && values[index].has_value())
        {
            current->right = new TreeNode(*values[index]);
            nodes.push(current->right);
        }
        index++;
    }

    return root;
}

static void print_tree(TreeNode* root)
{
    if (root == nullptr)
        return;

    std::cout << root->value << " ";
    print_tree(root->left);
    print_tree(root->right);
}

static void delete_tree(TreeNode* root)
{
    if (root == nullptr)
        return;

    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
}

#endif
