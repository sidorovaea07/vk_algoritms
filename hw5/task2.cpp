#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include "structures.h"

// Объединение K отсортированных массивов через мин-кучу.
// В кучу кладём пару (значение, номер_массива, индекс_в_массиве),
// берём минимум и подкладываем следующий элемент из того же массива.
// Сложность: O(N log K), где N - общее число элементов, K - число массивов.
struct Item
{
    int value;
    int array_index;
    int element_index;

    // std::priority_queue - max-куча, поэтому переворачиваем сравнение
    bool operator>(const Item& other) const { return value > other.value; }
};

std::vector<int> merge_k_sorted(const std::vector<std::vector<int>>& arrays)
{
    std::priority_queue<Item, std::vector<Item>, std::greater<Item>> min_heap;

    for (int i = 0; i < static_cast<int>(arrays.size()); ++i)
        if (!arrays[i].empty())
            min_heap.push({arrays[i][0], i, 0});

    std::vector<int> result;
    while (!min_heap.empty())
    {
        Item top = min_heap.top();
        min_heap.pop();
        result.push_back(top.value);

        int next_index = top.element_index + 1;
        if (next_index < static_cast<int>(arrays[top.array_index].size()))
            min_heap.push({arrays[top.array_index][next_index], top.array_index, next_index});
    }

    return result;
}

int main()
{
    fix_console_encoding();
    std::cout << "Задача 2: Объединение K отсортированных массивов" << std::endl;

    std::vector<std::vector<int>> arrays = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}
    };

    std::vector<int> merged = merge_k_sorted(arrays);
    std::cout << "Результат: ";
    for (int value : merged)
        std::cout << value << " ";
    std::cout << std::endl;

    return 0;
}
