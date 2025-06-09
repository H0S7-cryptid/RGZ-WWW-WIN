#include "STRUCT.h"

TV* initTV(TV* tv, char* name, char* brand,  int price, 
	 char screenSize, ST screentype, short refreshrate) {
	if (tv == NULL) {
		tv = (TV*)malloc(sizeof(TV));
		if (!tv) return NULL;
	}

	strcpy_s(tv->name, MAX_TV_NAME, name);
	strcpy_s(tv->brand, MAX_BRAND_NAME, brand);

	if (tryPrice(price)) tv->price = price;
	else tv->price = 0;

	if (tryScreenSize(screenSize)) tv->screenSize = screenSize;
	else tv->screenSize = 0;

	if (tryScreenType(screentype)) tv->screentype = screentype;
	else tv->screentype = UNDEFS;

	if (tryRefreshRate(refreshrate)) tv->refreshRate = refreshrate;
	else tv->refreshRate = 0;

	return tv;
}

int tryPrice(int price) {
	if (price < 0 || price > 1000000) return 0;
	return 1;
}

int tryScreenSize(char scrsize) {
	if (scrsize < 0 || scrsize > 800) return 0;
	return 1;
}

int tryScreenType(ST screentype) {
	if (screentype < 0 || screentype > 5) return 0;
	return 1;
}

int tryRefreshRate(short refreshrate) {
	if (refreshrate < 0 || refreshrate > 1000) return 0;
	return 1;
}

char* CreateScreenTypeForm(ST st) {
	
	if (st == LED) {
		char* format_str = (char*)malloc(sizeof(char) * 4);
		if (!format_str) return NULL;
		strcpy_s(format_str, 4, "LED");
		return format_str;
	}
	else if (st == OLED) {
		char* format_str = (char*)malloc(sizeof(char) * 5);
		if (!format_str) return NULL;
		strcpy_s(format_str, 5, "OLED");
		return format_str;
	}
	else if (st == QLED) {
		char* format_str = (char*)malloc(sizeof(char) * 5);
		if (!format_str) return NULL;
		strcpy_s(format_str, 5, "QLED");
		return format_str;
	}
	else if (st == LCD) {
		char* format_str = (char*)malloc(sizeof(char) * 4);
		if (!format_str) return NULL;
		strcpy_s(format_str, 4, "LCD");
		return format_str;
	}
	else if (st == MiniLED) {
		char* format_str = (char*)malloc(sizeof(char) * 8);
		if (!format_str) return NULL;
		strcpy_s(format_str, 8, "MiniLED");
		return format_str;
	}
	else if (st == MicroLED) {
		char* format_str = (char*)malloc(sizeof(char) * 9);
		if (!format_str) return NULL;
		strcpy_s(format_str, 9, "MicroLED");
		return format_str;
	}
	else return NULL;
}

void printTV(TV* tv) {
	char* ScreenType = CreateScreenTypeForm(tv->screentype);
	printf("\tBrand: %s\n", tv->brand);
	printf("\tName: %s\n", tv->name);
	printf("\tPrice: %d Rub\n", tv->price);
	printf("\tRefresh rate: %d Hz\n", tv->refreshRate);
	printf("\tScreen size (in inches): %d \n", tv->screenSize);
	printf("\tScreen type: %s\n", ScreenType);
}

int isEqualStr(const char* name1, const char* name2) {
	int r = strcmp(name1, name2);
	if (r == 0) return GROUPS_ARE_EQUAL;
	if (r < 0) return GROUP1_IS_SMALLER;
	return GROUP2_IS_SMALLER;
}

int isEqualPrice(const int price1, const int price2) {
	if (price1 == price2) return GROUPS_ARE_EQUAL;
	if (price1 < price2) return GROUP1_IS_SMALLER;
	return GROUP2_IS_SMALLER;
}

int isEqualScreenSize(char scrsize1, char scrsize2) {
	if (scrsize1 == scrsize2) return GROUPS_ARE_EQUAL;
	if (scrsize1 < scrsize2) return GROUP1_IS_SMALLER;
	return GROUP2_IS_SMALLER;
}

int isEqualScreenType(ST st1, ST st2) {
	if (st1 == st2) return GROUPS_ARE_EQUAL;
	if (st1 < st2) return GROUP1_IS_SMALLER;
	return GROUP2_IS_SMALLER;
}

int isEqualRefreshRate(short rr1, short rr2) {
	if (rr1 == rr2) return GROUPS_ARE_EQUAL;
	if (rr1 < rr2) return GROUP1_IS_SMALLER;
	return GROUP2_IS_SMALLER;
}

int IsEqualTV(TV* t1, TV* t2) {
	int r1 = isEqualStr(t1->brand, t2->brand) == GROUPS_ARE_EQUAL;
	int r2 = isEqualStr(t1->name, t2->name) == GROUPS_ARE_EQUAL;
	int r3 = isEqualPrice(t1->price, t2->price) == GROUPS_ARE_EQUAL;
	int r4 = isEqualScreenSize(t1->screenSize, t2->screenSize) == GROUPS_ARE_EQUAL;
	int r5 = isEqualScreenType(t1->screentype, t2->screentype) == GROUPS_ARE_EQUAL;
	int r6 = isEqualRefreshRate(t1->refreshRate, t2->refreshRate) == GROUPS_ARE_EQUAL;

	if (r1 && r2 && r3 && r4 && r5 && r6) return GROUPS_ARE_EQUAL;
	return GROUPS_ARE_NOT_EQUAL;
}

int WhichTVIsSmaller(TV* t1, TV* t2) {
	if (t1 == NULL) return GROUP1_IS_SMALLER;
	if (t2 == NULL) return GROUP2_IS_SMALLER;

	if (isEqualStr(t1->brand, t2->brand) != GROUPS_ARE_EQUAL) 
		return isEqualStr(t1->brand, t2->brand);

	if (isEqualStr(t1->name, t2->name) != GROUPS_ARE_EQUAL) 
		return isEqualStr(t1->name, t2->name);

	if (isEqualScreenSize(t1->screenSize, t2->screenSize) != GROUPS_ARE_EQUAL) 
		return isEqualScreenSize(t1->screenSize, t2->screenSize);

	if (isEqualScreenType(t1->screentype, t2->screentype) != GROUPS_ARE_EQUAL) 
		return isEqualScreenType(t1->screentype, t2->screentype);

	if (isEqualRefreshRate(t1->refreshRate, t2->refreshRate) != GROUPS_ARE_EQUAL) 
		return isEqualRefreshRate(t1->refreshRate, t2->refreshRate);

	if (isEqualPrice(t1->price, t2->price) != GROUPS_ARE_EQUAL) 
		return isEqualPrice(t1->price, t2->price);

	return GROUPS_ARE_EQUAL;
}
