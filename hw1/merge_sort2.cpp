#include <stdio.h>
#include <stdlib.h>

void merge_sorted_arrays(int *arr1, size_t len1, int *arr2, size_t len2)
{
    int p3 = (int)(len1 + len2 - 1),
        p2 = (int)(len2 - 1),
        p1 = (int)(len1 - 1);

    while (p2 >= 0) {
        if (p1 >= 0 && arr1[p1] > arr2[p2]) 
            arr1[p3] = arr1[p1--];
        else
            arr1[p3] = arr2[p2--];
        p3--;
    }

    return;
}

int main()
{
    size_t len1 = 0, len2 = 0;
    printf("Enter len1 and len2 of the arrays ");
    scanf("%zu%zu", &len1, &len2);

    int *arr1 = (int *) calloc(len1 + len2, sizeof(int));
    int *arr2 = (int *) calloc(len2, sizeof(int));

    if (!arr1 || !arr2) {
        perror("Mem error\n");
        return 0;
    }
    
    printf("Enter elements 1\n");
    for (size_t i = 0; i < len1; i++)
        scanf("%d", arr1 + i); 

    
    printf("Enter elements 2\n");
    for (size_t i = 0; i < len2; i++)
        scanf("%d", arr2 + i); 

    merge_sorted_arrays(arr1, len1, arr2, len2);
    printf("The answer: \n");

    for (size_t i = 0; i < len1 + len2; i++)
        printf("%d ", *(arr1 + i));
        
    free(arr1);
    free(arr2);

    putchar('\n');
}