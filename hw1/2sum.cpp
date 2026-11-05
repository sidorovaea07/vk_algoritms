// Дан отсортированный по возрастанию массив целых чисел 
// и некоторое число target.
// Необходимо найти два числа в массиве, 
// которые в сумме дают заданное значение target, 
// и вернуть их индексы.

#include <stdio.h>
#include <stdlib.h>

typedef struct PairOfPoints {
    size_t ileft;
    size_t iright;    
} pair;

pair twoSum(int *nums, size_t len, int target) 
{
    pair p = {0, len ? len - 1 : 0};

    while (p.ileft < p.iright) {
        int sum = nums[p.ileft] + nums[p.iright];

        if (sum == target)
            return p;
        else if (sum < target)
            p.ileft++;
        else
            p.iright--;
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

    if (p.ileft < p.iright)
        printf("The answer: %zu, %zu", p.ileft, p.iright);
    else
        printf("Couldn't make this kinda sum\n");
    free(nums);
}