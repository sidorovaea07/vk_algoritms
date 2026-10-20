#include "list.cpp" 


list_node* find_middle(list_node* head) 
{
    if (!head) 
        return nullptr;
    
    list_node* slow = head;
    list_node* fast = head;
    
    while (fast->next && fast->next->next) 
    {
        slow = slow->next;       
        fast = fast->next->next; 
    }
    
    return slow;  // slow указывает на середину
}


int main()
{
    std::cout << "Задача 2: Середина списка" << std::endl;
    list_node* list2 = create_list({1, 2, 3, 4, 5, 6, 7});
    std::cout << "Список: ";
    print_list(list2);
    list_node* middle = find_middle(list2);
    std::cout << "Середина: " << middle->val << std::endl;
    delete_list(list2);
    return 0;
}