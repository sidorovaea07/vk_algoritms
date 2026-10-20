#include <iostream>
#include <string>
#include <vector>

struct list_node 
{
    int val;
    list_node* next;
    
    list_node(int x) : val(x), next(nullptr) {}
};

list_node* create_list(const std::vector<int>& values) 
{
    if (values.empty()) 
        return nullptr;
    
    list_node* head = new list_node(values[0]);
    list_node* current = head;
    
    for (size_t i = 1; i < values.size(); ++i) 
    {
        current->next = new list_node(values[i]);
        current = current->next;
    }
    
    return head;
}

void print_list(list_node* head) 
{
    list_node* current = head;
    while (current) 
    {
        std::cout << current->val;
        if (current->next) std::cout << " -> ";
        current = current->next;
    }
    std::cout << std::endl;
}

void delete_list(list_node* head) 
{
    while (head) 
    {
        list_node* temp = head;
        head = head->next;
        delete temp;
    }
}

