#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

void generateRandomArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000 + 1;
    }
}

void writeRandomNumbersToFile(const char *filename, int n)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Generate and write n random numbers to the file
    for (int i = 0; i < n; i++)
    {
        fprintf(file, "%d\n", rand() % 1000 + 1); // Generating random numbers between 1 and 1000
    }

    fclose(file);
}

void readFromFile(int arr[], int n, const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++)
    {
        fscanf(file, "%d", &arr[i]);
    }

    fclose(file);
}

int main()
{
    int ns[] = {10, 50, 100, 200, 500, 1000};

    clock_t start, end;
    double cpu_time_used;

    for (int i = 0; i < sizeof(ns) / sizeof(ns[0]); i++)
    {
        int n = ns[i];
        int *arr = (int *)malloc(n * sizeof(int));

        readFromFile(arr, n, "input.txt");

        start = clock();
        quickSort(arr, 0, n - 1);
        end = clock();

        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("Time taken to sort %d elements: %f seconds\n", n, cpu_time_used);

        free(arr);
    }

    printf(" from file \n");

    for (int i = 0; i < sizeof(ns) / sizeof(ns[0]); i++)
    {
        int n = ns[i];
        int *arr = (int *)malloc(n * sizeof(int));

        readFromFile(arr, n, "input.txt"); // Change the filename as needed

        start = clock();
        quickSort(arr, 0, n - 1);
        end = clock();

        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("Time taken to sort %d elements: %f seconds\n", n, cpu_time_used);

        free(arr);
    }
    return 0;
}