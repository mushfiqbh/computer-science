#include <stdio.h>
#include <string.h>

int lexicographic_sort(const char *a, const char *b)
{
    return strcmp(a, b);
}

int lexicographic_sort_reverse(const char *a, const char *b)
{
    return strcmp(b, a);
}

int count_distinct_characters(const char *str)
{
    int count[256] = {0};

    for (int i = 0; str[i]; i++)
    {
        count[(unsigned char)str[i]] = 1;
    }

    int distinct_count = 0;
    for (int i = 0; i < 256; i++)
    {
        if (count[i])
            distinct_count++;
    }

    return distinct_count;
}

int sort_by_number_of_distinct_characters(const char *a, const char *b)
{
    int count_a = count_distinct_characters(a);
    int count_b = count_distinct_characters(b);

    if (count_a < count_b)
        return -1;
    else if (count_a > count_b)
        return 1;
    else
        return strcmp(a, b);
}

int sort_by_length(const char *a, const char *b)
{
    size_t len_a = strlen(a);
    size_t len_b = strlen(b);

    if (len_a < len_b)
        return -1;
    else if (len_a > len_b)
        return 1;
    else
        return strcmp(a, b);
}

void string_sort(const char **arr, const int cnt, int (*cmp_func)(const char *a, const char *b))
{
    for (int i = 0; i < cnt - 1; i++)
    {
        for (int j = 0; j < cnt - i - 1; j++)
        {
            if (cmp_func(arr[j], arr[j + 1]) > 0)
            {
                const char *temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    const char *input[n];
    for (int i = 0; i < n; i++)
    {
        char buffer[100];
        scanf("%s", buffer);
        input[i] = strdup(buffer);
    }

    string_sort(input, n, lexicographic_sort);

    for (int i = 0; i < n; i++)
    {
        printf("%s\n", input[i]);
    }

    printf("\n");
    string_sort(input, n, lexicographic_sort_reverse);

    for (int i = 0; i < n; i++)
    {
        printf("%s\n", input[i]);
    }

    printf("\n");
    string_sort(input, n, sort_by_number_of_distinct_characters);

    for (int i = 0; i < n; i++)
    {
        printf("%s\n", input[i]);
    }

    printf("\n");
    string_sort(input, n, sort_by_length);

    for (int i = 0; i < n; i++)
    {
        printf("%s\n", input[i]);
    }

    return 0;
}
