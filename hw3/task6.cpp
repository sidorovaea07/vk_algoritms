#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

std::vector<std::vector<std::string>> groupAnagrams(const std::vector<std::string>& strs) 
{
    std::unordered_map<std::string, std::vector<std::string>> anagram_groups;

    for (const std::string& s : strs) 
    {
        std::string sorted_s = s;
        std::sort(sorted_s.begin(), sorted_s.end()); // Сортируем слово для получения ключа
        
        // Добавляем оригинальное слово в соответствующую группу
        anagram_groups[sorted_s].push_back(s);
    }

    // Собираем все сгруппированные векторы в один итоговый результат
    std::vector<std::vector<std::string>> result;
    for (auto& pair : anagram_groups) 
        result.push_back(pair.second);

    return result;
}

int main() 
{
    std::cout << "Задача 6: Массив анаграмм" << std::endl;
    std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto result = groupAnagrams(strs);

    std::cout << "Результат группировки:" << std::endl;
    for (const auto& group : result) 
    {
        std::cout << "[ ";
        for (const auto& word : group) 
            std::cout << "\"" << word << "\" ";
        std::cout << "] ";
    }
    
    std::cout << std::endl;
    return 0;
}
