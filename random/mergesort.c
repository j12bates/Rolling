#include <stdio.h>
#include <stdlib.h>

// Function declarations
int *merge(int *, size_t);
void display(int *);

// Pointer to array and size
size_t size;
int* data;

int main(void)
{
    // Input array length
    scanf("%llu", &size);

    // Allocate memory for storing the array
    data = calloc(size, sizeof(int));
    if (data == NULL) return 1;

    // Input ints into array
    for (int i = 0; i < size; i++) {
        scanf("%d", data + i);
    }
    display(data);
    
    // Treat the array as having sorted sublists of length 1; now merge
    // sublists until it is all one sorted list
    for (int subSize = 1; subSize < size; subSize *= 2) {
        data = merge(data, subSize);
        if (data == NULL) return 1;
        display(data);
    }

    free(data);
    return 0;
}

// Display the current data array of ints
void display(int *src)
{
    for (int i = 0; i < size; i++) {
        printf("%d, ", src[i]);
    }
    printf("\n");
}

// Take an array of ints which is made up of sorted 'sublists' of a
// given length, merge adjacent pairs of sublists so that they're now
// twice as long
int *merge(int *src, size_t subSize)
{
    // Allocate memory for storing the result
    int *res = calloc(size, sizeof(int));
    if (res == NULL) return NULL;

    // Go through 'sublists' two at a time
    for (int head = 0; head < size; head += subSize * 2) {

        // Indices for each sublist
        int i = 0, j = 0;

        // Merge from sublists until one is exhausted, pay attention to
        // the array bounds
        while (i < subSize && j < subSize && head + subSize + j < size)
        {
            int a = src[head + i];
            int b = src[head + subSize + j];
            if (a < b) {
                res[head + i + j] = a;
                i++;
            } else {
                res[head + i + j] = b;
                j++;
            }
        }

        // One of these is exhausted, copy the remains from the other
        for (; i < subSize && head + i < size; i++)
            res[head + i + j] = src[head + i];
        for (; j < subSize && head + subSize + j < size; j++)
            res[head + i + j] = src[head + subSize + j];
    }

    // Free memory from the source
    free(src);

    return res;
}
