#include "list.cpp"


bool is_subsequence(const std::string& a, const std::string& b) 
{
    if (a.length() > b.length()) 
        return false;
    
    int i = 0; 
    int j = 0; 
    
    while (i < a.length() && j < b.length()) 
    {
        if (a[i] == b[j]) 
            i++; 
        j++; 
    }
    
    return i == a.length();
}


int main()
{
    std::cout << "Задача 4: Подпоследовательность" << std::endl;
    std::string a = "abc";
    std::string b = "ahbgdc";
    std::cout << "a = \"" << a << "\", b = \"" << b << "\"" << std::endl;
    std::cout << "Результат: " << (is_subsequence(a, b) ? "true" : "false") << std::endl;
    return 0;
}