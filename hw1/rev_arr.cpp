// Дан массив целых чисел.
// Необходимо развернуть его.
// Сделать это надо за линейное время без дополнительных
// аллокаций.

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
    return;
}

void reverseArray(int *arr, size_t len)
{
    int *left = arr;
    int *right = arr + len - 1;

    while (left < right) {
        swap(left, right);
        left++;
        right--;
    }
}

int main()
{
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

    reverseArray(nums, len);
    printf("The answer: \n");

    for (size_t i = 0; i < len; i++)
        printf("%d ", *(nums + i)); 

    
    free(nums);
    putchar('\n');
}