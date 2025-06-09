int main() {
	TV t1, t2;

	initTV(&t1, "Samsung UE60JU6800K", "Samsung", 150000, 70, QLED, 150);

	initTV(&t2, "Samsung UE60JU6800K", "Samsung", 100000, 60, LED, 122);

	printTV(&t1);
	printTV(&t2);

	int is_eq = IsEqualTV(&t1, &t2) == GROUPS_ARE_EQUAL;

	int what_is_smaller = WhichGroupIsSmaller(&t1, &t2);

	printf("Are these two TV`s equal? Anwser: %d\n", is_eq);
	printf("Which one of these TVs is smaller? Anwser: %d\n", what_is_smaller);

	return 0;
}
