#include <iostream>
#include <queue>
#include <vector>
#include "structures.h"


// Поиск K-го наименьшего элемента через max-кучу размера K.
// Держим в куче K наименьших элементов, вершина кучи - наибольший из них.
// После прохода вершина и есть K-й наименьший.
// Сложность: O(N log K) по времени, O(K) по памяти.
// Для K-го наибольшего - ищем (N - K + 1)-й наименьший.
int kth_smallest(const std::vector<int>& numbers, int k)
{
    std::priority_queue<int> max_heap;  // по умолчанию max-куча

    for (int value : numbers)
    {
        max_heap.push(value);
        if (static_cast<int>(max_heap.size()) > k)
            max_heap.pop();  // выкидываем самый большой
    }

    return max_heap.top();
}

int kth_largest(const std::vector<int>& numbers, int k)
{
    return kth_smallest(numbers, static_cast<int>(numbers.size()) - k + 1);
}

int main()
{
    fix_console_encoding();
    std::cout << "Задача 3: K-ый наименьший / наибольший элемент" << std::endl;

    std::vector<int> numbers = {7, 10, 4, 3, 20, 15};
    int k = 3;

    std::cout << "Массив: ";
    for (int value : numbers)
        std::cout << value << " ";
    std::cout << "\nK = " << k << std::endl;

    std::cout << k << "-й наименьший: " << kth_smallest(numbers, k) << std::endl;
    std::cout << k << "-й наибольший: " << kth_largest(numbers, k) << std::endl;

    return 0;
}

