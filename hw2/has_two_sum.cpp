#include "list.cpp"

bool has_two_sum(const std::vector<int>& sortedArr, int target) 
{
    int left = 0;
    int right = sortedArr.size() - 1;
    
    while (left < right) 
    {
        int sum = sortedArr[left] + sortedArr[right];
        
        if (sum == target) 
            return true;
        else if (sum < target) 
            left++;  // Увеличиваем сумму
        else 
            right--; // Уменьшаем сумму
    }
    
    return false;
}

int main()
{
    std::cout << "Задача 5: Поиск пары с суммой" << std::endl;
    std::vector<int> arr = {1, 2, 3, 4, 5, 6};
    int target = 9;
    std::cout << "Массив: [1, 2, 3, 4, 5, 6], target = " << target << std::endl;
    std::cout << "Результат: " << (has_two_sum(arr, target) ? "true" : "false") << std::endl;
    return 0;
}
