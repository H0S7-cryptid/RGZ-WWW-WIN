#ifndef STRUCT
#define STRUCT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define MAX_TV_NAME 30
#define MAX_BRAND_NAME 10
#define BUFF_SIZE 5

enum check_number { NUM_IS_GOOD = 0, NUM_IS_BAD = -1 };

enum group_comparison_eq { GROUPS_ARE_EQUAL = 0, GROUPS_ARE_NOT_EQUAL = -1 };

enum group_comparison_sm_bg { GROUP1_IS_SMALLER = -1, GROUP2_IS_SMALLER = 1 };

typedef enum ScreenType { LED, OLED, QLED, LCD, MiniLED, MicroLED, UNDEFS = - 1 } ST;

struct Television {
	char name[MAX_TV_NAME];			// Название модели телевизора
	char brand[MAX_BRAND_NAME];		// Бренд телевизора
	int price;						// Цена телевизора
	char screenSize;				// Размер диагонали в дюймах
	ST screentype;					// Тип матрицы экрана
	short refreshRate;				// Частота обновления кадров в Гц
}; 

typedef struct Television TV;

// Функция для инициализации полей структуры
TV* initTV(TV* tv, char* name, char* brand, int price,
	char screenSize, ST screentype, short refreshrate);

// Функции для проверки соответствующих полей структуры
int tryPrice(int price);
int tryScreenSize(char scrsize);
int tryScreenType(ST screentype);
int tryRefreshRate(short refreshrate);

// Функция для создания строки с информацией о типе дисплея
char* CreateScreenTypeForm(ST st);

// Функция вывода информации о структуре
void printTV(TV* tv);

// Функции проверки отдельных полей структуры
int isEqualStr(const char* name1, const char* name2);
int isEqualPrice(const int price1, const int price2);
int isEqualScreenSize(char scrsize1, char scrsize2);
int isEqualScreenType(ST st1, ST st2);
int isEqualRefreshRate(short rr1, short rr2);

// Функция проверки на равенство структур
int IsEqualTV(TV* t1, TV* t2);

// Функция проверки на неравенство структур
int WhichTVIsSmaller(TV* t1, TV* t2);

#endif
