#include <stdio.h>
#include <stdlib.h>

void merge_sorted_arrays(int *merged, int *arr1, size_t len1, int *arr2, size_t len2)
{
    size_t i = 0, j = 0, k = 0;

    while (i < len1 && j < len2) {
        if (arr1[i] < arr2[j]) 
            merged[k++] = arr1[i++];
        else
            merged[k++] = arr2[j++];
    }

    while (i < len1) {
        merged[k++] = arr1[i++]; 
    }

    while (j < len2) {
        merged[k++] = arr2[j++]; 
    }

    return;
}

int main()
{
    size_t len1 = 0, len2 = 0;
    printf("Enter len1 and len2 of the arrays ");
    scanf("%zu%zu", &len1, &len2);

    int *arr1 = (int *) calloc(len1, sizeof(int));
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

    int *merged = (int *)calloc(len1 + len2, sizeof(int));

    if (!merged) {
        perror("Mem error\n");
        return 0;
    }

    merge_sorted_arrays(merged, arr1, len1, arr2, len2);
    printf("The answer: \n");

    for (size_t i = 0; i < len1 + len2; i++)
        printf("%d ", *(merged + i));
        
    free(arr1);
    free(arr2);
    free(merged);

    putchar('\n');
}