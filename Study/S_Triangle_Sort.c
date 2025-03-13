#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
    int a;
    int b;
    int c;
};

typedef struct triangle triangle;

void sort_by_area(triangle *arr, int n)
{
    double new_arr[n];
    triangle temp;

    for (int i = 0; i < n; i++)
    {
        double area, p;
        p = ((arr[i].a + arr[i].b + arr[i].c) / 2.0);
        area = (p * (p - arr[i].a) * (p - arr[i].b) * (p - arr[i].c));
        new_arr[i] = area;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (new_arr[i] > new_arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;

                int temp_area = new_arr[i];
                new_arr[i] = new_arr[j];
                new_arr[j] = temp_area;
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    triangle *arr = malloc(n * sizeof(triangle));
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &arr[i].a, &arr[i].b, &arr[i].c);
    }
    sort_by_area(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d %d %d\n", arr[i].a, arr[i].b, arr[i].c);
    }
    return 0;
}
