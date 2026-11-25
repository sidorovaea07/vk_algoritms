#include <iostream>
#include <vector>

// Треугольник Паскаля

std::vector<std::vector<int>> build_pascal(int n)
{
    std::vector<std::vector<int>> triangle;

    for (int i = 0; i < n; ++i) {
        // строка i содержит (i + 1) элемент, все инициализируем единицами
        std::vector<int> row(i + 1, 1);

        // внутренние элементы считаем по предыдущей строке
        for (int j = 1; j < i; ++j)
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];

        triangle.push_back(row);
    }

    return triangle;
}

void print_triangle(const std::vector<std::vector<int>>& triangle)
{
    for (const auto& row : triangle) {
        for (int value : row)
            std::cout << value << " ";
        std::cout << std::endl;
    }
}

int main()
{
    std::cout << "Задача 2: Треугольник Паскаля" << std::endl;

    int n = 5;
    std::cout << "n = " << n << std::endl;

    std::vector<std::vector<int>> triangle = build_pascal(n);
    print_triangle(triangle);

    return 0;
}
