#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(const std::vector<int>& nums, int target) {
    std::unordered_map<int, int> seen;

    for (int i = 0; i < nums.size(); ++i) 
    { 
        int complement = target - nums[i];
        
        // Проверяем, видели ли мы уже парное число
        if (seen.find(complement) != seen.end()) 
            return {seen[complement], i}; // Возвращаем индексы пары
        
        // Запоминаем текущее число
        seen[nums[i]] = i;
    }
    
    return {}; // Если пара не найдена
}

int main() 
{
    std::cout << "Задача 5: Сумма двух элементов массива" << std::endl;
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    std::vector<int> result = twoSum(nums, target);
    
    if (!result.empty())
        std::cout << "Индексы элементов: [" << result[0] << ", " << result[1] << "]" << std::endl;
    else 
        std::cout << "Пара не найдена" << std::endl;
    
    return 0;
}
