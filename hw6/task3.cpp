#include <iostream>
#include <vector>

// Размен монет 

int coin_change(const std::vector<int>& coins, int amount)
{
    const int INF = amount + 1;  // заведомо больше любого реального ответа
    std::vector<int> dp(amount + 1, INF);
    dp[0] = 0;  // сумму 0 набрать можно нулём монет

    for (int x = 1; x <= amount; ++x) {
        for (int coin : coins) {
            if (coin <= x && dp[x - coin] != INF) {
                int candidate = dp[x - coin] + 1;
                if (candidate < dp[x])
                    dp[x] = candidate;
            }
        }
    }

    return dp[amount] == INF ? -1 : dp[amount];
}

int main()
{
    std::cout << "Задача 3: Размен монет" << std::endl;

    std::vector<int> coins1 = {1, 2, 5};
    int amount1 = 11;
    std::cout << "coins = [1, 2, 5], amount = " << amount1
              << " -> " << coin_change(coins1, amount1) << " (Ожидается: 3)" << std::endl;

    std::vector<int> coins2 = {2};
    int amount2 = 3;
    std::cout << "coins = [2], amount = " << amount2
              << " -> " << coin_change(coins2, amount2) << " (Ожидается: -1)" << std::endl;

    return 0;
}
