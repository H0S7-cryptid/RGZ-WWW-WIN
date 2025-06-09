#ifndef FILE_FUNC
#define FILE_FUNC

#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/stat.h>

// Функция для записи данных из существующего списка
void CreateAndOrWriteTV(const char* file_name, node** head);

// Функиця для получения информации о записанных структурах и добавление их в список
void GetTVFromFile(const char* file_name, node* head);

#endif
