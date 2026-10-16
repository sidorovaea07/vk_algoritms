#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
    return;
}

void even_first(int *nums, size_t len)
{
    int even_idx = 0;

    for (size_t i = 0; i < len; i++) {
        if (nums[i] % 2 == 0) {
            swap(nums + i, nums + even_idx);
            even_idx++;
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

    even_first(nums, len);

    for (size_t i = 0; i < len; i++)
        printf("%d ", *(nums + i));

    free(nums);
}