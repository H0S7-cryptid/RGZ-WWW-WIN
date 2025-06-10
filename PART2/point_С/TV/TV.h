#ifndef TV_
#define TV_

#include "Audio&Video.h"


class TV: public AudioAndVideo {
private:
	float screensize;		// Длина диагонали в дюймах
	int resolutionWidth;	// Ширина разрешения картинки
	int resolutionHeight;	// Высота разрешения картинки
	ScreenType screentype;	// Тип матрицы экрана

	void Init(ScreenType screentype, int resolutionWidth, int resolutionHeight, float screensize);
public:
	// Конструкторы
	TV();
	TV(std::string name, std::string brand, double price,
		ScreenType screentype, int resolutionWidth, int resolutionHeight, float screensize);
	TV(const TV& other);

	// Оператор присваивания
	TV& operator=(const TV& other);

	// Сеттеры полей
	void setName(std::string str);
	void setBrand(std::string str);
	void setPrice(double price);
	void setScreenType(ScreenType screentype);
	void setScreenSize(float screensize);
	void setResolutionWidth(int resolutionWidth);
	void setResolutionHeight(int resolutionHeight);

	// Геттеры полей
	std::string getName() const;
	std::string getBrand() const;
	double getPrice() const;
	ScreenType getScreenType() const;
	float getScreenSize() const;
	std::string getResolution() const;

	// Оператор вывода в поток
	virtual std::ostream& print(std::ostream& out) const override;
	friend std::ostream& operator<<(std::ostream& out, const TV& tv);
};

#endif
