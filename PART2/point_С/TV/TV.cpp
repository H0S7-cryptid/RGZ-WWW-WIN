#include "TV.h"

// Вспомогательные закрытые функции класса
void TV::Init(ScreenType screentype, int resolutionWidth, int resolutionHeight, float screensize) {
	if (resolutionWidth > 7680 || resolutionWidth < 0) this->resolutionWidth = 0;
	else this->resolutionWidth = resolutionWidth;

	if (resolutionHeight > 4320 || resolutionHeight < 0) this->resolutionHeight = 0;
	else this->resolutionHeight = resolutionHeight;

	if (screensize > 100 || screensize < 0) this->screensize = 0;
	else this->screensize = screensize;

	this->screentype = screentype;
}

// Конструкторы
TV::TV() : AudioAndVideo(), screentype{ ScreenType::UNDEFS }, screensize{ 0.0 }, resolutionWidth{ 0 }, resolutionHeight{ 0 } {}
TV::TV(std::string name, std::string brand, double price, ScreenType screentype, 
	int resolutionWidth, int resolutionHeight, float screensize): AudioAndVideo(name, brand, price) {
	Init(screentype, resolutionWidth, resolutionHeight, screensize);
}
TV::TV(const TV& other): AudioAndVideo(other.name, other.brand, other.price) {
	Init(other.screentype, other.resolutionWidth, other.resolutionHeight, other.screensize);
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
std::ostream& TV::print(std::ostream& out) const {
	AudioAndVideo::print(out);
	out << "\tResolution: " << getResolution() << std::endl;
	out << "\tScreen size: " << screensize << std::endl;
	out << "\tScreen type: " << TVScreenName[screentype] << std::endl;
	out << "\tPrice: " << price << std::endl << std::endl;
	return out;

}
std::ostream& operator<<(std::ostream& out, const TV& tv) {
	return tv.print(out);
}
