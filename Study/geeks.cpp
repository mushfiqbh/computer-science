#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 5;

    int **bookShelf = (int **)malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++)
    {
        bookShelf[i] = (int *)malloc(1 * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", bookShelf[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        free(bookShelf[i]);
    }

    free(bookShelf);

    return 0;
}
