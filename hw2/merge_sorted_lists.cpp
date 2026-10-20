#include "list.cpp"

list_node* merge_sorted_lists(list_node* list1, list_node* list2) 
{
    list_node dummy(0); // временный узел
    list_node* tail = &dummy;
    
    while (list1 && list2) 
    {
        if (list1->val <= list2->val) 
        {
            tail->next = list1;
            list1 = list1->next;
        } 
        else 
        {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }
    
    tail->next = list1 ? list1 : list2;
    
    return dummy.next;
}


int main()
{
    std::cout << "Задача 8: Слияние списков" << std::endl;
    list_node* l1 = create_list({3, 6, 8});
    list_node* l2 = create_list({4, 7, 9, 11});
    std::cout << "Список 1: ";
    print_list(l1);
    std::cout << "Список 2: ";
    print_list(l2);
    list_node* merged = merge_sorted_lists(l1, l2);
    std::cout << "Слияние: ";
    print_list(merged);
    delete_list(merged);
    return 0;
}