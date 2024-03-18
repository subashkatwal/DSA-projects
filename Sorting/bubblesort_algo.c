#include <stdio.h>
#define MAX_SIZE 50
void sorting(int size, int arr[]);
int main()
{
    int i, size, arr[MAX_SIZE], j;
    printf("Enter the size of the array :\n");
    scanf("%d", &size);
    printf("Insert the unsorted array :\n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    sorting(size, arr);
}

void sorting(int size, int arr[])
{
    int i, j, temp;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("The sorted array using Bubble sort is :\n");
    for (i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}