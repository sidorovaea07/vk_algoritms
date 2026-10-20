#include "list.cpp"

bool is_palindrome(const std::string& str) 
{
    int left = 0;
    int right = str.length() - 1;
    
    while (left < right) 
    {
        if (str[left] != str[right]) 
            return false;
        left++;
        right--;
    }
    
    return true;
}

int main()
{
    std::cout << "Задача 6: Палиндром" << std::endl;
    std::string word1 = "madam";
    std::string word2 = "hello";
    std::cout << "\"" << word1 << "\" - " << (is_palindrome(word1) ? "палиндром" : "не палиндром") << std::endl;
    std::cout << "\"" << word2 << "\" - " << (is_palindrome(word2) ? "палиндром" : "не палиндром") << std::endl;
    return 0;
}
