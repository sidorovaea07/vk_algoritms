// Дан отсортированный по возрастанию массив целых чисел 
// и некоторое число target.
// Необходимо найти два числа в массиве, 
// которые в сумме дают заданное значение target, 
// и вернуть их индексы.

#include <stdio.h>
#include <stdlib.h>

typedef struct PairOfPoints {
    int *left;
    int *right;    
} pair;

pair twoSum(int *nums, size_t len, int target) 
{
    pair p = {nums, nums + len - 1};

    int sum = 0;

    while (p.left < p.right) {
        sum = *(p.left) + *(p.right);

        if (sum == target)
            return p;
        else if (sum < target)
            (p.left)++;
        else
            (p.right)--;
    }

    return p;
}

int main()
{
    int target = 0;
    printf("Enter target ");
    scanf("%d", &target);
    
    size_t len = 0;
    printf("Enter len of the array ");
    scanf("%zu", &len);

    int *nums = (int *) calloc(len, sizeof(int));

    if (!nums) {
        perror("Mem error\n");
        return 0;
    }

    printf("Enter elements\n");
    for (size_t i = 0; i < len; i++)
        scanf("%d", nums + i);

    pair p = twoSum(nums, len, target);

    if (*(p.left) + *(p.right) == target)
        printf("The answer: %d, %d", *(p.left), *(p.right));
    else
        printf("Couldn't make this kinda sum\n");
    free(nums);
}