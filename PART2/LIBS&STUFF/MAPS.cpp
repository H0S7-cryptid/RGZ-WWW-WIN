#include "LIBS.h"

extern std::map <ScreenType, std::string> TVScreenName = {
	{ScreenType::LED, "LED"},
	{ScreenType::OLED, "OLED"},
	{ScreenType::QLED, "QLED"},
	{ScreenType::LCD, "LCD"},
	{ScreenType::MiniLED, "Mini LED"},
	{ScreenType::MicroLED, "Micro LED"},
	{ScreenType::UNDEFS, "Undefined"}
};

extern std::map <SuppFreq, std::string> SuppFreqName = {
	{SuppFreq::LF, "Low Frequencies"},
	{SuppFreq::MF, "Middle Frequencies"},
	{SuppFreq::HF, "High Frequencies"},
	{SuppFreq::VHF, "Very High Frequencies"},
	{SuppFreq::UHF, "Ultra High Frequencies"},
	{SuppFreq::DAB, "Digital Digital Audio Broadcasting"},
	{SuppFreq::UNDEFF, "Undefined"}
};

extern std::map <Tuner, std::string> TunerName = {
	{Tuner::Analog, "Analog Tuner"},
	{Tuner::Digital, "Digital Tuner"},
	{Tuner::UNDEFT, "Undefined"}
};

extern std::map <IsPortable, std::string> IsPortableName = {
	{IsPortable::YES, "Yes"},
	{IsPortable::NO, "No"},
	{IsPortable::UNDEFIP, "Undefined"}
};
