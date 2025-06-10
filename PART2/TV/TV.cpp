#include "TV.h"

// Вспомогательные закрытые функции класса
void TV::Init(std::string name, std::string brand, double price, ScreenType screentype, int resolutionWidth, int resolutionHeight, float screensize) {
	try {
		tryString(name);
		this->name = name;
	}
	catch (std::logic_error& e) {
		std::cerr << e.what() << std::endl;
		this->name = "Unknown";
	}
	catch (std::invalid_argument& e) {
		std::cerr << e.what() << std::endl;
		this->name = "Unknown";
	}

	try {
		tryString(brand);
		this->brand = brand;
	}
	catch (std::logic_error& e) {
		std::cerr << e.what() << std::endl;
		this->brand = "Unknown";
	}
	catch (std::invalid_argument& e) {
		std::cerr << e.what() << std::endl;
		this->brand = "Unknown";
	}

	if (price < 0.0 || price > 10000000.0) this->price = 0;
	else this->price = price;

	if (resolutionWidth > 7680 || resolutionWidth < 0) this->resolutionWidth = 0;
	else this->resolutionWidth = resolutionWidth;

	if (resolutionHeight > 4320 || resolutionHeight < 0) this->resolutionHeight = 0;
	else this->resolutionHeight = resolutionHeight;

	if (screensize > 100 || screensize < 0) this->screensize = 0;
	else this->screensize = screensize;

	this->screentype = screentype;
}
void TV::tryString(std::string str) {
	if (str.empty())
		throw std::logic_error("Empty input!");

	if (!std::isupper(str[0]))
		str[0] = (char)toupper(str[0]);

	for (int i = 0; i < str.size(); i++) {
		char ch = str[i];
		if (std::isspace(ch)) continue;

		if (std::isalnum(ch)) {
			if (std::isalpha(ch) && !std::islower(ch))
				str[i] = (char)tolower(ch);
			else continue;
		}
		else throw std::invalid_argument("Incorrect input (prohibited special symbols)!");
	}
}

// Конструкторы
TV::TV() : name{ "Unknown" }, brand{ "Unknown" }, price{ 0.0 },
screentype{ ScreenType::UNDEFS }, screensize{ 0.0 }, resolutionWidth{ 0 }, resolutionHeight{ 0 } {}
TV::TV(std::string name, std::string brand, double price, ScreenType screentype, int resolutionWidth, int resolutionHeight, float screensize) {
	Init(name, brand, price, screentype, resolutionWidth, resolutionHeight, screensize);
}
TV::TV(const TV& other) {
	Init(other.name, other.brand, other.price, other.screentype, other.resolutionWidth, other.resolutionHeight, other.screensize);
}

// Оператор присваивания 
TV& TV::operator=(const TV& other) {
	if (this != &other) {
		this->name = other.name;
		this->brand = other.brand;
		this->price = other.price;
		this->screentype = other.screentype;
		this->resolutionWidth = other.resolutionWidth;
		this->resolutionHeight = other.resolutionHeight;
		this->screensize = other.screensize;
	}
	return *this;
}

// Сеттеры
void TV::setName(std::string str) {
	try {
		tryString(str);
		this->name = str;
	}
	catch (std::logic_error& e) {
		std::cerr << e.what() << std::endl;
		this->name = "Unknown";
	}
	catch (std::invalid_argument& e) {
		std::cerr << e.what() << std::endl;
		this->name = "Unknown";
	}
}
void TV::setBrand(std::string str) {
	try {
		tryString(str);
		this->brand = str;
	}
	catch (std::logic_error& e) {
		std::cerr << e.what() << std::endl;
		this->brand = "Unknown";
	}
	catch (std::invalid_argument& e) {
		std::cerr << e.what() << std::endl;
		this->brand = "Unknown";
	}
}
void TV::setPrice(double price) {
	if (price < 0.0 || price > 10000000.0) this->price = 0;
	else this->price = price;
}
void TV::setScreenType(ScreenType screentype) {
	this->screentype = screentype;
}
void TV::setScreenSize(float screensize) {
	if (screensize > 100 || screensize < 0) this->screensize = 0;
	else this->screensize = screensize;
}
void TV::setResolutionWidth(int resolutionWidth) {
	if (resolutionWidth > 7680 || resolutionWidth < 0) this->resolutionWidth = 0;
	else this->resolutionWidth = resolutionWidth;
}
void TV::setResolutionHeight(int resolutionHeight) {
	if (resolutionHeight > 4320 || resolutionHeight < 0) this->resolutionHeight = 0;
	else this->resolutionHeight = resolutionHeight;
}

// Геттеры
std::string TV::getName() const {
	return name;
}
std::string TV::getBrand() const {
	return brand;
}
double TV::getPrice() const {
	return price;
}
ScreenType TV::getScreenType() const {
	return screentype;
}
float TV::getScreenSize() const {
	return screensize;
}
std::string TV::getResolution() const {
	std::string part1 = std::to_string(resolutionWidth);
	std::string part2 = std::to_string(resolutionHeight);
	std::string result;
	result.append(part1);
	result.append(" X ");
	result.append(part2);

	return result;
}

// Оператор вывода данных телевизора в поток 
std::ostream& operator<<(std::ostream& out, const TV& tv) {
	out << "Current TV Specifications" << std::endl;
	out << "\tModel: " << tv.name << std::endl;
	out << "\tBrand: " << tv.brand << std::endl;
	out << "\tResolution: " << tv.getResolution() << std::endl;
	out << "\tScreen size: " << tv.screensize << std::endl;
	out << "\tScreen type: " << TVScreenName[tv.screentype] << std::endl;
	out << "\tPrice: " << tv.price << std::endl << std::endl;
	return out;
}
