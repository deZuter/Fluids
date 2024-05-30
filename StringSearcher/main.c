#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifdef WINDOWS
#include <Windows.h>
#include <locale.h>
#endif // WINDOWS


#define START_HEAP_SIZE 128
#define MAX_LENGTH 1024

//toInput - не обязательный параметр
//обязательно потом очистить возвращенный массив строк
char** StringInput(char *toInput, int* count) 
{
    int strCount = NULL;
    scanf("%d", &strCount);
    getchar();

    char** strings = (char**)malloc(sizeof(char*) * strCount);
    if (!strings)
    {
        printf("Ошибка выделения памяти!\n");
        return -1;
    }
    printf("Введите %s через Enter: \n", toInput);
    for (int i = 0; i < strCount; i++)
    {
        char buffer[MAX_LENGTH];
        scanf("%s", &buffer);
        getchar();
#ifdef WINDOWS
        strings[i] = _strdup(buffer);
#else // WINDOWS
        strings[i] = strdup(buffer);
#endif


        if (!strings[i])
        {
            printf("Ошибка выделения памяти!\n");
            return -1;
        }
    }

    printf("Вы ввели:\n");
    for (int i = 0; i < strCount; i++) {
        printf("%d: %s\n", i + 1, strings[i]);
    }
    *count = strCount;
    return strings;
}

typedef struct 
{
    int start; //для того, чтобы задать, с какого файла начать
    int end;   //для того, чтобы задать, каким файлом закончить
    int stringsCount;
    char** strings;
    char** filePaths;
} ThreadData;

#ifdef WINDOWS
size_t getline(char **linePtr, int *n, FILE* file) 
{
    size_t pos = 0;
    int c = 0;
    size_t size = *n;

    if (linePtr == NULL || n == NULL || file == NULL) 
    {
        return -1;
    }

    if (*linePtr == NULL) 
    {
        size = 128; //начальный размер
        
        *linePtr = (char*)malloc((size_t)(size));
        memset(*linePtr, 0, size);
        if (*linePtr == NULL) 
        {
            return -1;
        }
    }
    
    while (c != EOF) 
    {
        c = fgetc(file);
        if (c == -1) 
        {
            break;
        }
        //если буфер переполнен
        if (pos + 1 >= size) 
        {
            size_t new_size = *n * 2;
            char *new_linePtr = realloc(*linePtr, new_size);
            if (new_linePtr == NULL)
            {
                return -1;
            }
            *linePtr = new_linePtr;
            *n = new_size;
        }

        (*linePtr)[pos] = c;
        if ( (*linePtr)[pos] == '\n') 
        {
            break;
        }
        pos++;
    }
    *n = size;
    if (pos > 0) 
    {
        pos++;
        (*linePtr)[pos] = '\0';
        return pos;
    }
    //если ничего не прочитано

    return -1;

}
#endif
void* SearchStringsInFiles(void* threadData) 
{
    //реализовать поиск строк в файле
    ThreadData* data = (ThreadData*)threadData;
    char *line = NULL;

    for (int i = data->start; i < data->end; i++) 
    {
        FILE* file = fopen(data->filePaths[i], "r+");
        int read = 0;
        int strPos = 0;
        int len = NULL;
        while (read = getline(&line, &len, file) != -1)
        {
            for (int j = 0; j < data->stringsCount; j++) 
            {
                if (strstr(line, data->strings[j])) 
                {
                    printf("\nFile: %s String: %s Pos: %d", data->filePaths[i], data->strings[j], strPos);
                }
            }
            strPos++;
            free(line);
            line = NULL;
        }
        free(line);
        line = NULL;
        len = NULL;
        
        fclose(file);
    }
}



int main(int argc, char **argv)
{
#ifdef WINDOWS
    setlocale(LC_ALL, "Rus");
#endif
    int stringsCount = 1;
    printf("Введите количество строк для поиска: ");
    char** strings = StringInput("строки", &stringsCount);

    int filesCount = 1;
    printf("Введите количество файловых путей для поиска: ");
    char** filePaths = StringInput("файловые пути", &filesCount);

    //узнать количество процессоров
    int cpuCount = 0;
#ifdef WINDOWS
    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);
    cpuCount = sysInfo.dwNumberOfProcessors;
#else
    cpuCount = sysconf(_SC_NPROCESSORS_ONLN);
#endif
    int countFilesForThread = 0;
    countFilesForThread = filesCount / cpuCount;

    //если количество файлов меньше количества потоков, то мы создаем по потоку для файла
    if (countFilesForThread == 0) 
    {
        countFilesForThread = 1;
        cpuCount = filesCount;
    }


    ThreadData* data = (ThreadData*)malloc(sizeof(ThreadData) * cpuCount);
    if (!data)
    {
        return -1;
    }

#ifdef WINDOWS
    HANDLE* threads = (HANDLE*)malloc(sizeof(HANDLE*) * cpuCount);
    if (!threads) 
    {
        return -1;
    }

    for (int i = 0; i < cpuCount; i++) 
    {
        data[i].start = i * countFilesForThread;
        data[i].end = data[i].start + countFilesForThread;
        data[i].filePaths = filePaths;
        data[i].strings = strings;
        data[i].stringsCount = stringsCount;
        threads[i] = CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)SearchStringsInFiles, (void*)&(data[i]), NULL, NULL);
    }
    WaitForMultipleObjects(cpuCount, threads, TRUE, INFINITE);
#else 
    //создание и запуск потоков на юникс системах
#endif // WINDOWS


    for (int i = 0; i < stringsCount; i++)
    {
        free(strings[i]);
    }
    free(strings);
    for (int i = 0; i < filesCount; i++)
    {
        free(filePaths[i]);
    }
    free(filePaths);
    free(data);
    free(threads);

}