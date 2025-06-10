#include "TV.h"
#include "Radio.h"

// Прототипы вспомогательных функций
void addObject(std::list<AudioAndVideo*>& objects);
void printObjects(const std::list<AudioAndVideo*>& objects);
void cleanupObjects(std::list<AudioAndVideo*>& objects);

// Функция для ввода строки с учётом пробелов
std::string inputString(const std::string& prompt) {
	std::cout << prompt;
	std::string s;
	std::getline(std::cin, s);
	return s;
}

int main() {
	std::list<AudioAndVideo*> objects;
	int choice = 0;
	bool running = true;

	while (running) {
		std::cout << "\nMenu:\n"
			<< " 1. Add an object\n"
			<< " 2. Print all objects\n"
			<< " 3. Exit\n"
			<< "Enter your choice: ";
		std::cin >> choice;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // очистка буфера ввода

		switch (choice) {
		case 1:
			addObject(objects);
			break;
		case 2:
			printObjects(objects);
			break;
		case 3:
			running = false;
			break;
		default:
			std::cout << "Invalid choice. Please try again." << std::endl;
		}
	}

	cleanupObjects(objects);
	return 0;
}

void addObject(std::list<AudioAndVideo*>& objects) {
	int type = 0;
	std::cout << "\nSelect the type of object to add:\n"
		<< " 1. AudioAndVideo\n"
		<< " 2. Radio\n"
		<< " 3. TV\n"
		<< "Enter numberof the type:";
	std::cin >> type;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	AudioAndVideo* obj = nullptr;

	if (type == 1) {
		obj = new AudioAndVideo();
		// Ввод общих данных
		std::string name = inputString("Enter model: ");
		std::string brand = inputString("Enter brand: ");
		double price;
		std::cout << "Enter price: ";
		std::cin >> price;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		obj->setName(name);
		obj->setBrand(brand);
		obj->setPrice(price);
	}
	else if (type == 2) {
		obj = new Radio();
		// Ввод общих данных
		std::string name = inputString("Enter model: ");
		std::string brand = inputString("Enter brand: ");
		double price;
		std::cout << "Enter price: ";
		std::cin >> price;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		// Ввод специфичных для Radio данных
		int tunerInt;
		std::cout << "Enter Tuner (0-Analog, 1-Digital): ";
		std::cin >> tunerInt;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		int isPortableInt;
		std::cout << "Is it portable? (1 for yes, 0 for no): ";
		std::cin >> isPortableInt;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		int suppFreqInt;
		std::cout << "Enter Supported Frequency \n(0-LF, 1-MF, 2-HF, 3-VHF, 4-UHF, 5-DAB): ";
		std::cin >> suppFreqInt;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		// Устанавливаем поля через сеттеры базового класса
		obj->setName(name);
		obj->setBrand(brand);
		obj->setPrice(price);

		// Приводим к типу Radio для установки специфичных полей
		Radio* radioObj = dynamic_cast<Radio*>(obj);
		if (radioObj) {
			radioObj->setTuner(static_cast<Tuner>(tunerInt));
			radioObj->setIsPort(static_cast<IsPortable>(isPortableInt));
			radioObj->setSuppFreq(static_cast<SuppFreq>(suppFreqInt));
		}
	}
	else if (type == 3) {
		obj = new TV();
		// Ввод общих данных
		std::string name = inputString("Enter model: ");
		std::string brand = inputString("Enter brand: ");
		double price;
		std::cout << "Enter price: ";
		std::cin >> price;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		// Ввод специфичных для TV данных
		int screenTypeInt;
		std::cout << "Enter Screen Type \n(0-LED, 1-OLED, 2-QLED, 3-LCD, 4-MiniLED, 5-MicroLED): ";
		std::cin >> screenTypeInt;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		int resWidth;
		std::cout << "Enter Resolution Width: ";
		std::cin >> resWidth;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		int resHeight;
		std::cout << "Enter Resolution Height: ";
		std::cin >> resHeight;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		float screenSize;
		std::cout << "Enter Screen Size (in inches): ";
		std::cin >> screenSize;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		obj->setName(name);
		obj->setBrand(brand);
		obj->setPrice(price);

		TV* tvObj = dynamic_cast<TV*>(obj);
		if (tvObj) {
			tvObj->setScreenType(static_cast<ScreenType>(screenTypeInt));
			tvObj->setResolutionWidth(resWidth);
			tvObj->setResolutionHeight(resHeight);
			tvObj->setScreenSize(screenSize);
		}
	}
	else {
		std::cout << "Invalid type selected." << std::endl;
		return;
	}

	objects.push_back(obj);
	std::cout << "Object added successfully." << std::endl;
}

// Функция вывода списка объектов
void printObjects(const std::list<AudioAndVideo*>& objects) {
	if (objects.empty()) {
		std::cout << "\nList is empty." << std::endl;
		return;
	}

	std::cout << "\nList of objects:" << std::endl;
	for (auto obj : objects) {
		std::cout << *obj << std::endl;
	}
}

void cleanupObjects(std::list<AudioAndVideo*>& objects) {
	for (auto obj : objects)
		delete obj;
	objects.clear();
}
