#include "LR_List.h"

node* HeadTracker(node* head) {
	char buffer[BUFF_SIZE];
	char item = 0;

	fgets(buffer, BUFF_SIZE, stdin);
	if (IsTrueNumber(buffer) && atoi(buffer) < 4 && atoi(buffer) > 0) item = (char)atoi(buffer);

	switch (item) {
	case 1: {
		TV tv;
		tv = CreateUserTV();
		head = Insert(head, tv);
		break;
	}
	case 2: {
		PrintList(head);
		break;
	}
	case 3: {
		printf("Enter delete position: ");
		int pos = 0;
		fgets(buffer, BUFF_SIZE, stdin);
		if (IsTrueNumber(buffer)) pos = atoi(buffer);

		head = Delete(head, pos);
		break;
	}
	}
	return head;
}

int main() {

	node* head = NULL;

	char buffer_for_item[BUFF_SIZE];
	int item;

	printf("Work with Linked Ordered List.\n");
	printf("Select action:\n1. Add new element\n2. Printf all list\n3. Delete element by position\n\n");
	while (1)
	{
		head = HeadTracker(head);
		printf("Закончить работу со списком? (0 - Нет, 1\\Enter - Да)\n");
		fgets(buffer_for_item, BUFF_SIZE, stdin); 
		item = atoi(buffer_for_item);
		if (item == 0 && head != NULL) continue;
		else break;
	}

	DeleteList(&head);

	return 0;
}
