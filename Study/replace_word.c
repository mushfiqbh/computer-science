#include <stdio.h>
#include <string.h>

int main()
{
    char text[100];

    fgets(text, sizeof(text), stdin);

    text[strcspn(text, "\n")] = '\0';

    char *result = strstr(text, "hate");

    if (result != NULL)
    {
        strncpy(result, "love", 4);
    }

    printf("%s", text);
    return 0;
}
