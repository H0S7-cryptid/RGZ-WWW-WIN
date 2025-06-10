#include "Audio&Video.h"

// Вспомогательные функции
void AudioAndVideo::Init(std::string name, std::string brand, double price) {
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

	if (price < 0 || price > 10000000.0) this->price = 0;
	else  this->price = price;
}
void AudioAndVideo::tryString(std::string str) {
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
AudioAndVideo::AudioAndVideo() : name{ "Unknown" }, brand{ "Unknown" }, price{0.0} {}
AudioAndVideo::AudioAndVideo(std::string name, std::string brand, double price) {
	Init(name, brand, price);
}
AudioAndVideo::AudioAndVideo(const AudioAndVideo& other) {
	Init(name, brand, price);
}

AudioAndVideo& AudioAndVideo::operator=(const AudioAndVideo& other) {
	if (this != &other) {
		this->name = other.name;
		this->brand = other.brand;
		this->price = price;
	}
	return *this;
}

// Сеттеры
void AudioAndVideo::setName(std::string name) {
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
}
void AudioAndVideo::setBrand(std::string brand) {
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
}
void AudioAndVideo::setPrice(double price) {
	if (price < 0 || price > 10000000.0) this->price = 0;
	else  this->price = price;
}

// Геттеры
std::string AudioAndVideo::getName() const {
	return name;
}
std::string AudioAndVideo::getBrand() const {
	return brand;
}
double AudioAndVideo::getPrice() const {
	return price;
}

// Оператор вывода в поток
std::ostream& operator<<(std::ostream& out, const AudioAndVideo& av) {
	std::cout << "Basic Specifications of Audio- and Videodevices" << std::endl;
	out << "Model: " << av.name << std::endl;
	out << "Brand: " << av.brand << std::endl;
	out << "Price: " << av.price << std::endl;
	return out;
}
