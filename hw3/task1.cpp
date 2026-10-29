#include <iostream>

int mySqrt(int n) {
    if (n < 2) 
        return n;

    int left = 1, right = n;
    int ans = 0;

    while (left <= right) 
    {
        int mid = left + (right - left) / 2;

        if (mid <= n / mid) 
        {  
            ans = mid;      // Запоминаем возможный ответ
            left = mid + 1; // Ищем большее значение в правой половине
        } 
        else 
            right = mid - 1; // Ищем в левой половине
    }
    return ans;
}

int main() 
{
    std::cout << "Задача 1: Найти корень числа" << std::endl;
    int num = 27;
    std::cout << "Корень из " << num << " (округленный вниз): " << mySqrt(num) << " (Ожидается: 5)" << std::endl;
    return 0;
}
