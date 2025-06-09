#include "LR_list.h"

int IsTrueNumber(char* number)
{
	const char* special_symbols = "\\|~`!@#$%^&*()_+=?:%;№";
	if (strpbrk(number, special_symbols) != NULL) return NUM_IS_BAD;

	if (number[0] == '\0' || number[0] == '\n' || number[0] == '/') return NUM_IS_BAD;

	int is_negative = (number[0] == '-') ? 1 : 0;

	size_t start_idx = is_negative ? 1 : 0, len = strlen(number);

	if (number[len] == '\n') number[len] = '\0';

	if (len == 0 && is_negative == 1) return NUM_IS_BAD;

	for (size_t i = start_idx; i < len; i++) if (isalpha(number[i])) return NUM_IS_BAD;

	return NUM_IS_GOOD;
}

void PrintList(node* head) {
	node* temp = head;
	int pos = 1;
	printf("Current elements in list:\n");
	while (temp != NULL) {
		printf("Tv-%d:", pos);
		printTV(&temp->data);
		temp = temp->next;
	}
}

void DeleteList(node** head) {
	if (head == NULL || *head == NULL) return;
	while (*head != NULL) {
		node* temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}

node* Insert(node* head, TV tv) {

	node* new_node = (node*)malloc(sizeof(node));
	if (!new_node) return head;
	new_node->data = tv;
	new_node->next = NULL;

	if (head == NULL || WhichTVIsSmaller(&head->data, &tv) != GROUP1_IS_SMALLER) {
		new_node->next = head;
		return new_node;
	}

	node* current = head;
	while (current->next != NULL &&
		WhichTVIsSmaller(&current->next->data, &tv) == GROUP1_IS_SMALLER) {
		current = current->next;
	}

	new_node->next = current->next;
	current->next = new_node;

	return head;
}

int GetNumOfNodes(node* head) {
	int size = 0;
	node* temp = head;

	if (head == NULL) return size;

	while (temp != NULL) {
		temp = temp->next;
		size++;
	}

	return size;
}

node* Delete(node* head, int delete_pos) {
	if (delete_pos <= 0 || head == NULL) return head;

	if (delete_pos == 1) {
		node* temp = head;
		head = head->next;
		free(temp);
		return head;
	}

	node* current = head;
	node* prev = NULL;
	int pos = 1;
	while (current != NULL && pos < delete_pos) {
		prev = current;
		current = current->next;
		pos++;
	}

	if (current == NULL) return head;

	prev->next = current->next;
	free(current);

	return head;
}

node* GetTV(node** head, int grab_pos) {
	if (grab_pos <= 0 || head == NULL || *head == NULL) return NULL;

	node* removed = NULL;

	if (grab_pos == 1) {
		removed = *head;
		*head = (*head)->next;
		removed->next = NULL;
		return removed;
	}

	node* current = *head;
	node* prev = NULL;
	int pos = 1;
	while (current != NULL && pos < grab_pos) {
		prev = current;
		current = current->next;
		pos++;
	}

	if (current == NULL) return NULL;

	prev->next = current->next;
	current->next = NULL;

	return current;
}

void clearInputBuffer(void) {
	int ch;
	while ((ch = getchar()) != '\n' && ch != EOF);
}

void removeNewline(char* str, size_t buf_size) {
	size_t len = strlen(str);

	if (len > 0 && str[len - 1] == '\n') str[len - 1] = '\0';

	else clearInputBuffer();
}

TV CreateUserTV() {
	TV tv;
	char buffer[BUFF_SIZE];

	char brand[MAX_BRAND_NAME];
	char name[MAX_TV_NAME];
	int price = 0;
	char screenSize = 0;
	ST screentype = 0;
	short refreshRate = 0;

	printf("Type in brand of the TV: ");
	if (fgets(brand, MAX_BRAND_NAME, stdin) != NULL) removeNewline(brand, MAX_BRAND_NAME);

	printf("Type in name of the TV: ");
	if (fgets(name, MAX_TV_NAME, stdin) != NULL) removeNewline(name, MAX_TV_NAME);

	printf("Type in screen size of the TV: ");
	if (fgets(buffer, BUFF_SIZE, stdin) != NULL) {
		removeNewline(buffer, BUFF_SIZE);
		if (IsTrueNumber(buffer) == NUM_IS_GOOD)
			screenSize = (char)atoi(buffer);
	}

	printf("Type in screen type of the TV - LED (0), OLED (1), QLED (2), LCD (3), MiniLED (4), MicroLED (5)\n");
	if (fgets(buffer, BUFF_SIZE, stdin) != NULL) {
		removeNewline(buffer, BUFF_SIZE);
		if (IsTrueNumber(buffer) == NUM_IS_GOOD)
			screentype = (ST)atoi(buffer);
	}

	printf("Type in refresh rate of the TV's screen: ");
	if (fgets(buffer, BUFF_SIZE, stdin) != NULL) {
		removeNewline(buffer, BUFF_SIZE);
		if (IsTrueNumber(buffer) == NUM_IS_GOOD)
			refreshRate = (short)atoi(buffer);
	}

	printf("Type in price of the TV: ");
	if (fgets(buffer, BUFF_SIZE, stdin) != NULL) {
		removeNewline(buffer, BUFF_SIZE);
		if (IsTrueNumber(buffer) == NUM_IS_GOOD)
			price = atoi(buffer);
	}

	initTV(&tv, name, brand, price, screenSize, screentype, refreshRate);
	return tv;
}
