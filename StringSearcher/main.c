#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024




int main(int argc, char **argv)
{
    int strCount = NULL;
    printf("Введите количество строк для поиска: ");
    scanf("%d", &strCount);
    getchar();

    char** strings = (char**)malloc(sizeof(char*)*strCount);
    if (!strings)
    {
        printf("Ошибка выделения памяти!\n");
        return -1;
    }
    printf("Введите строки через Enter: \n");
    for(int i = 0; i < strCount; i++)
    {
        char buffer[MAX_LENGTH];
        scanf("%s", &buffer);
        getchar();
        strings[i] = strdup(buffer);
        if (!strings[i])
        {
            printf("Ошибка выделения памяти!\n");
            return -1;
        }
    }

    printf("Введенные строки:\n");
    for (int i = 0; i < strCount; i++) {
        printf("%d: %s\n", i + 1, strings[i]);
    }

}