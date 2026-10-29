#include <iostream>
#include <algorithm>

bool isEnoughTime(int T, int N, int x, int y) 
{
    return (T / x) + (T / y) >= N;
}

int getMinTime(int N, int x, int y) 
{
    if (N == 0) 
        return 0;

    int first_copy = std::min(x, y);
    if (N == 1) 
        return first_copy;

    int left = 0;
    int right = (N - 1) * std::min(x, y); 
    int best_time = right;

    while (left <= right) 
    {
        int mid = left + (right - left) / 2;
        if (isEnoughTime(mid, N - 1, x, y)) 
        {
            best_time = mid;
            right = mid - 1; // Пытаемся найти меньшее время
        }
        else 
            left = mid + 1;  // Времени мало, нужно увеличить диапазон
    }

    return first_copy + best_time;
}

int main() 
{
    std::cout << "Задача 2: Очень легкая задача" << std::endl;
    int N = 5, x = 1, y = 2;
    std::cout << "Минимальное время для " << N << " копий: " 
              << getMinTime(N, x, y) << " мин. (Ожидается: 4)" << std::endl;
    return 0;
}
