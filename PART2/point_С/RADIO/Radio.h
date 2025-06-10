#ifndef RADIO
#define RADIO

#include "Audio&Video.h"

class Radio: public AudioAndVideo {
private:
	Tuner tuner;
	IsPortable isportable;
	SuppFreq suppfreq;

	void Init(Tuner tuner, IsPortable isportable, SuppFreq suppfreq);
public:
	// Конструкторы
	Radio();
	Radio(std::string name, std::string brand, double price, 
		Tuner tuner, IsPortable isportable, SuppFreq suppfreq);
	Radio(const Radio& other);

	// Оператор присваивания
	Radio& operator=(const Radio& other);

	// Сеттеры
	void setName(std::string str);
	void setBrand(std::string str);
	void setPrice(double price);
	void setTuner(Tuner tuner);
	void setIsPort(IsPortable isportable);
	void setSuppFreq(SuppFreq suppfreq);

	// Геттеры
	std::string getName() const;
	std::string getBrand() const;
	double getPrice() const;
	Tuner getTuner() const;
	IsPortable getIsPort() const;
	SuppFreq getSuppFreq() const;

	// Оператор вывода данных в поток
	virtual std::ostream& print(std::ostream& out) const override;
	friend std::ostream& operator<<(std::ostream& out, const Radio& radio);
};

#endif
