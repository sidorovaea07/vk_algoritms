#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <algorithm>
#include <iostream>
#include <optional>
#include <queue>
#include <vector>

#ifdef _WIN32
#include <windows.h>
// Переключаем кодировку консоли на UTF-8, чтобы кириллица печаталась корректно
static void fix_console_encoding()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
}
#else
static void fix_console_encoding() {}
#endif

struct TreeNode
{
    int value;
    TreeNode* left;
    TreeNode* right;
    int balance_factor;  // используется в задаче 5

    TreeNode(int val)
        : value(val), left(nullptr), right(nullptr), balance_factor(0) {}
};

// Построение дерева по массиву (уровневый порядок, nullopt = отсутствие узла)
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

// Построение BST вставкой (чтобы гарантировать свойство BST в задачах 4-5)
static TreeNode* insert_bst(TreeNode* root, int value)
{
    if (root == nullptr)
        return new TreeNode(value);

    if (value < root->value)
        root->left = insert_bst(root->left, value);
    else
        root->right = insert_bst(root->right, value);

    return root;
}

static TreeNode* build_bst(const std::vector<int>& values)
{
    TreeNode* root = nullptr;
    for (int value : values)
        root = insert_bst(root, value);
    return root;
}

// Прямой обход для печати
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

