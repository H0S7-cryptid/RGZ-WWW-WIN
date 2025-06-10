#ifndef AUDIO_AND_VIDEO
#define AUDIO_AND_VIDEO

#include "LIBS.h"

class AudioAndVideo {
protected:
	std::string name;
	std::string brand;
	double price;

	void tryString(std::string str);
	void Init(std::string name, std::string brand, double price);
public:
	// Конструкторы
	AudioAndVideo();
	AudioAndVideo(std::string name, std::string brand, double price);
	AudioAndVideo(const AudioAndVideo& other);

	AudioAndVideo& operator=(const AudioAndVideo& other);

	// Сеттеры
	void setName(std::string name);
	void setBrand(std::string brand);
	void setPrice(double price);

	// Геттеры
	std::string getName() const;
	std::string getBrand() const;
	double getPrice() const;

	// Оператор вывода в поток
	friend std::ostream& operator<<(std::ostream& out, const AudioAndVideo& av);
};

#endif // !1
