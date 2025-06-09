#ifndef LR_LIST
#define LR_LIST

#include "STRUCT.h"

struct node_of_linked_list {
	TV data;
	struct node_of_linked_list* next;
};

typedef struct node_of_linked_list node;

// Функция вставки элемента в упорядоченный односвязный список
node* Insert(node* head, TV tv);

// Функция для подсчёта количества элементов
int GetNumOfNodes(node* head);

// Функция удаления элемента списка по заданной позиции
node* Delete(node* head, int delete_pos);

// Функция для получения элемента из списка по заданной позиции
node* GetTV(node** head, int grab_pos);

// Функция для вывода информации о списке
void PrintList(node* head);

// Создание элемента списка с данными пользователя
TV CreateUserTV();

// Функция для удаления списка
void DeleteList(node** head);

// Методы для обработки потока ввода
void clearInputBuffer(void);
void removeNewline(char* str, size_t buf_size);
#endif
