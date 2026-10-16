#include <stdio.h>
#include <stdlib.h>

int min_sub_array(int *nums, int len, int target)
{
    int min_len = len;
    int left = 0;
    int curr_sum = 0;

    for (int right = 0; right < len; right++) {
        curr_sum += nums[right];

        while (curr_sum >= target) {
            int window_size = right - left + 1;
            if (window_size < min_len) {
                min_len = window_size;
            }
            curr_sum -= nums[left];
            left++;
        }
    }

    return min_len == len ? 0 : min_len; 
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

    printf("%d\n", min_sub_array(nums, (int)len, target));
    
    free(nums);
}