#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
    return;
}

void reverseArray(int *left, int *right)
{
    while (left < right) {
        swap(left, right);
        left++;
        right--;
    }
}

void solution(int *arr, size_t len, size_t k)
{
    reverseArray(arr, arr + len - 1);
    reverseArray(arr, arr + k - 1);
    reverseArray(arr + k, arr + len - 1);
}

int main()
{
    size_t k = 0;
    printf("Enter k ");
    scanf("%zu", &k);
    
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

    solution(nums, len, k);
    printf("The answer: \n");

    for (size_t i = 0; i < len; i++)
        printf("%d ", *(nums + i)); 

    free(nums);
    putchar('\n');
}