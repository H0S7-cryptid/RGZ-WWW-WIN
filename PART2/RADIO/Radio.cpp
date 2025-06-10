#include "Radio.h"

// Вспомогательные функции для 
void Radio::Init(std::string name, std::string brand, double price,
	Tuner tuner, IsPortable isportable, SuppFreq suppfreq) {
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
	
	this->tuner = tuner;
	this->isportable = isportable;
	this->suppfreq = suppfreq;
}
void Radio::tryString(std::string str) {
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

// Кострукторы
Radio::Radio() : name{ "Unknown" }, brand{ "Unknown" }, price{ 0.0 }, tuner{ Tuner::UNDEFT },
isportable{ IsPortable::UNDEFIP }, suppfreq{ SuppFreq::UNDEFF } {}
Radio::Radio(std::string name, std::string brand, double price,
	Tuner tuner, IsPortable isportable, SuppFreq suppfreq) {
	Init(name, brand, price, tuner, isportable, suppfreq);
}
Radio::Radio(const Radio& other) {
	Init(other.name, other.brand, other.price, other.tuner, other.isportable, other.suppfreq);
}

// Оператор присваивания
Radio& Radio::operator=(const Radio& other) {
	if (this != &other) {
		this->name = other.name;
		this->brand = other.brand;
		this->price = other.price;
		this->tuner = other.tuner;
		this->isportable = other.isportable;
		this->suppfreq = other.suppfreq;
	}
	return *this;
}

// Сеттеры
void Radio::setName(std::string str) {
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
void Radio::setBrand(std::string str) {
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
void Radio::setPrice(double price) {
	if (price < 0.0 || price > 10000000.0) this->price = 0;
	else this->price = price;
}
void Radio::setTuner(Tuner tuner) {
	this->tuner = tuner;
}
void Radio::setIsPort(IsPortable isportable) {
	this->isportable = isportable;
}
void Radio::setSuppFreq(SuppFreq suppfreq) {
	this->suppfreq = suppfreq;
}

// Геттеры
std::string Radio::getName() const {
	return name;
}
std::string Radio::getBrand() const {
	return brand;
}
double Radio::getPrice() const {
	return price;
}
Tuner Radio::getTuner() const {
	return tuner;
}
IsPortable Radio::getIsPort() const {
	return isportable;
}
SuppFreq Radio::getSuppFreq() const {
	return suppfreq;
}

// Оператор вывода в поток
std::ostream& operator<<(std::ostream& out, const Radio& radio) {
	out << "Current Radio specifications" << std::endl;
	out << "\tModel: " << radio.name << std::endl;
	out << "\tBrand: " << radio.brand << std::endl;
	out << "\tTyner type: " << TunerName[radio.tuner] << std::endl;
	out << "\tMaximum Supported Frequencies: " << SuppFreqName[radio.suppfreq] << std::endl;
	out << "\tPortableness: " << IsPortableName[radio.isportable] << std::endl << std::endl;
	return out;
}
