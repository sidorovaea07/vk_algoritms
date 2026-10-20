#include "list.cpp"

int remove_duplicates(std::vector<int>& sortedArr) 
{
    if (sortedArr.empty()) 
        return 0;
    
    int slow = 0; 
    
    for (int fast = 1; fast < sortedArr.size(); ++fast) 
    {
        if (sortedArr[fast] != sortedArr[slow]) 
        {
            slow++;
            sortedArr[slow] = sortedArr[fast];
        }
    }
    
    return slow + 1; 
}

int main()
{
    std::cout << "Задача 7: Удаление дубликатов" << std::endl;
    std::vector<int> dupArr = {1, 1, 2, 2, 3, 4, 4, 5};
    std::cout << "Исходный: [1, 1, 2, 2, 3, 4, 4, 5]" << std::endl;
    int uniqueCount = remove_duplicates(dupArr);
    std::cout << "Уникальных элементов: " << uniqueCount << std::endl;
    std::cout << "Результат: [";
    for (int i = 0; i < uniqueCount; ++i) 
    {
        std::cout << dupArr[i];
        if (i < uniqueCount - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
    return 0;
}
