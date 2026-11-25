#include <iostream>
#include <string>

// Максимальный палиндром в строке

// Возвращает длину палиндрома с центром между left и right
int expand_around_center(const std::string& s, int left, int right)
{
        while (left >= 0 && right < static_cast<int>(s.size()) && s[left] == s[right])
        {
            --left;
            ++right;
        }
        return right - left - 1;  // длина после выхода за границу совпадений
}

std::string longest_palindrome(const std::string& s)
{
    if (s.size() < 2)
        return s;

    int best_start = 0;
    int best_len = 1;

    for (int center = 0; center < static_cast<int>(s.size()); ++center)
        {
        // нечётная длина: центр в одном символе
        int len_odd = expand_around_center(s, center, center);
        // чётная длина: центр между центром и center + 1
        int len_even = expand_around_center(s, center, center + 1);

        int len = len_odd > len_even ? len_odd : len_even;

        if (len > best_len)
        {
            best_len = len;
            // начало подстроки: отступаем от центра на (len - 1) / 2
            best_start = center - (len - 1) / 2;
    }
}

    return s.substr(best_start, best_len);
}

int main()
{
    std::cout << "Задача 4: Максимальный палиндром в строке" << std::endl;

    std::string s1 = "babad";
    std::cout << "\"" << s1 << "\" -> \"" << longest_palindrome(s1) << std::endl;

    std::string s2 = "cbbd";
    std::cout << "\"" << s2 << "\" -> \"" << longest_palindrome(s2) << std::endl;

    std::string s3 = "forgeeksskeegfor";
    std::cout << "\"" << s3 << "\" -> \"" << longest_palindrome(s3) << std::endl;

    return 0;
}

