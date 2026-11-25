#include <iostream>
#include <vector>

// Наибольшая непрерывная возрастающая последовательность.

int longest_increasing_run(const std::vector<int>& nums) {
    if (nums.empty())
        return 0;

    int current_len = 1;  // любая одиночная последовательность длиной 1
    int max_len = 1;

    for (size_t i = 1; i < nums.size(); ++i) {
        if (nums[i] > nums[i - 1])
            current_len++;          // продолжаем рост
        else
            current_len = 1;        // сброс, начинаем новую с текущего

        if (current_len > max_len)
            max_len = current_len;  // обновляем лучший ответ
    }

    return max_len;
}

void print_array(const std::vector<int>& nums) {
    std::cout << "[";
    for (size_t i = 0; i < nums.size(); ++i)
    {
        std::cout << nums[i];
        if (i + 1 < nums.size())
            std::cout << ", ";
    }
    std::cout << "]";
}

int main()
{
    std::cout << "Задача 1: Наибольшая непрерывная возрастающая последовательность" << std::endl;

    std::vector<std::vector<int>> tests = {
        {3, 2, 8, 9, 5, 10},
        {1, 2, 7, 9, 0, 10},
        {8, 8, 8, 8}
    };

    for (const auto& nums : tests)
    {
        print_array(nums);
        std::cout << " -> " << longest_increasing_run(nums) << std::endl;
    }

    return 0;
}
