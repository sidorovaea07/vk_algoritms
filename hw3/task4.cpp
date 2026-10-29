#include <iostream>
#include <string>

char findTheDifference(const std::string& a, const std::string& b) {
    char result = 0;
    
    // Применяем XOR ко всем символам первой строки
    for (char c : a) 
        result ^= c;
    // Применяем XOR ко всем символам второй строки
    for (char c : b) 
        result ^= c;
           
    return result;
}

int main() 
{
    std::cout << "Задача 4: Разница строк" << std::endl;
    std::string a = "abcd";
    std::string b = "abcde";
    std::cout << "Добавленная буква: " << findTheDifference(a, b) << " (Ожидается: e)" << std::endl;
    return 0;
}
