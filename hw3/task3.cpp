#include <iostream>
#include <vector>
#include <algorithm>

int feedAnimals(std::vector<int>& animals, std::vector<int>& portions) 
{
    std::sort(animals.begin(), animals.end());
    std::sort(portions.begin(), portions.end());

    int animal_ptr = 0;
    int portion_ptr = 0;
    int fed_count = 0;

    // Двигаемся по обоим массивам
    while (animal_ptr < animals.size() && portion_ptr < portions.size()) 
    {
        // Если порция подходит животному
        if (portions[portion_ptr] >= animals[animal_ptr]) 
        {
            fed_count++;
            animal_ptr++;  // Переходим к следующему животному
        }
        portion_ptr++;     // Порция использована (или была слишком мала)
    }

    return fed_count;
}

int main() {
    std::cout << "Задача 3: Накормить животных" << std::endl;
    std::vector<int> animals = {3, 4, 2, 1}; // Аппетиты
    std::vector<int> portions = {1, 3, 2};   // Порции
    std::cout << "Накормлено животных: " << feedAnimals(animals, portions) << " (Ожидается: 3)" << std::endl;
    return 0;
}
