#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
    return;
}

void sort_colors(int *nums, size_t len)
{
    int low = 0, mid = 0, high = len - 1;

    while (mid <= high) {
        if (!nums[mid]) {
            swap(nums + low, nums + mid);
            low++, mid++;
        }
        else if (nums[mid] == 1)
            mid++;
        else if (nums[mid] == 2) {
            swap(nums + high, nums + mid);
            high--;
        }
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

    sort_colors(nums, len);

    for (size_t i = 0; i < len; i++)
        printf("%d", *(nums + i));

    free(nums);
}