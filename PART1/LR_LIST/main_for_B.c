#include "LR_List.h"

node* HeadTracker(node* head) {
	char buffer[BUFF_SIZE];
	int choice = 0;

	fgets(buffer, BUFF_SIZE, stdin);
	if (IsTrueNumber(buffer) == NUM_IS_GOOD) {
		choice = atoi(buffer);
	}

	switch (choice) {
	case 1: {
		TV tv = CreateUserTV();
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
		if (fgets(buffer, BUFF_SIZE, stdin) != NULL && IsTrueNumber(buffer)) {
			pos = atoi(buffer);
		}
		head = Delete(head, pos);
		break;
	}
	default:
		printf("Incorrect choice. Try again.\n");
		break;
	}
	return head;
}

int main() {
	node* head = NULL;
	char buffer_for_item[BUFF_SIZE];
	int stopEditing = 0;

	printf("Work with Linked Ordered List.\n");
	printf("Select action:\n");
	printf("1. Add new element\n");
	printf("2. Print entire list\n");
	printf("3. Delete element by position\n\n");

	while (1)
	{
		head = HeadTracker(head);

		printf("Stop editing the list? (0 - No, 1 - Yes): ");
		fgets(buffer_for_item, BUFF_SIZE, stdin);
		stopEditing = atoi(buffer_for_item); 

		if (stopEditing == 0)
			continue;
		else
			break;
	}

	DeleteList(&head);
	return 0;
}
