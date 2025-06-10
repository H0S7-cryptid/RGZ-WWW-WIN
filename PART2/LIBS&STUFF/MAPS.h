#ifndef MAPS
#define MAPS

#include <string>
#include <map>
#include "ENUM.h"

// Map для вывода типа экрана для телевизора
extern std::map <ScreenType, std::string> TVScreenName;

// Map для вывода перечислений для типа Radio
extern std::map <SuppFreq, std::string> SuppFreqName;
extern std::map <Tuner, std::string> TunerName;
extern std::map <IsPortable, std::string> IsPortableName;

#endif 
