#ifndef ENUM
#define ENUM

// Тип экрана для телевизора
enum class ScreenType : char { LED, OLED, QLED, LCD, MiniLED, MicroLED, UNDEFS = -1 };

// Перечисления для типа Radio
enum class SuppFreq : char { LF, MF, HF, VHF, UHF, DAB, UNDEFF = -1 };
enum class Tuner : char { Analog, Digital, UNDEFT = -1 };
enum class IsPortable : char { YES, NO, UNDEFIP = -1 };

#endif 
