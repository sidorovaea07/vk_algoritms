#include "list.cpp"

list_node* reverse_list(list_node* head) 
{
    list_node* prev = nullptr;
    list_node* current = head;
    list_node* next = nullptr;
    
    while (current != nullptr) 
    {
        next = current->next;  
        current->next = prev;  
        prev = current;        
        current = next;        
    }
    
    return prev;  
}


int main() 
{
    std::cout << "Задача 1: Разворот списка" << std::endl;
    list_node* list1 = create_list({1, 2, 3, 4, 5});
    std::cout << "Исходный: ";
    print_list(list1);
    list1 = reverse_list(list1);
    std::cout << "Развернутый: ";
    print_list(list1);
    delete_list(list1);
    return 0;
}