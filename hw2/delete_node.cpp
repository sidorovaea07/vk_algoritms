#include "list.cpp"


list_node* delete_node(list_node* head, int val) 
{
    if (!head) 
        return nullptr;
    
    if (head->val == val) 
    {
        list_node* newHead = head->next;
        delete head;
        return newHead;
    }
    
    list_node* current = head;
    while (current->next && current->next->val != val) 
    {
        current = current->next;
    }
    
    if (current->next) 
    {
        list_node* nodeToDelete = current->next;
        current->next = current->next->next;
        delete nodeToDelete;
    }
    
    return head;
}

int main()
{
    std::cout << "Задача 3: Удаление элемента" << std::endl;
    list_node* list3 = create_list({1, 2, 3, 4, 5});
    std::cout << "Исходный: ";
    print_list(list3);
    list3 = delete_node(list3, 3);
    std::cout << "После удаления 3: ";
    print_list(list3);
    delete_list(list3);

}