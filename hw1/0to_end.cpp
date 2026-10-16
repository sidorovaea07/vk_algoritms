#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
    return;
}

void nulls_to_end(int *nums, size_t len)
{
    int null_idx = len - 1, i = 0;

    while (i < null_idx) {
        if (!nums[i]) {
            swap(nums + i, nums + null_idx);
            null_idx--;
        }
        i++;
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

    nulls_to_end(nums, len);

    for (size_t i = 0; i < len; i++)
        printf("%d ", *(nums + i));

    free(nums);
}