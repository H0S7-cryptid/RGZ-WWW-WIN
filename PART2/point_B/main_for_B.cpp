#include "TV.h"
#include "Radio.h"

int main() {
	std::cout << "\t\t\tBASE-CLASS (NON-DYNAMIC)" << std::endl;

	AudioAndVideo anv;

	std::cout << anv;

	anv.setName("Samsung Television");
	anv.setBrand("Samsung");
	anv.setPrice(15000.0);

	std::cout << anv;

	std::cout << "\t\t\tBASE-CLASS (DYNAMIC)" << std::endl;

	AudioAndVideo* anv_ = &anv;

	std::cout << *anv_;

	TV t1{ anv.getName(), anv.getBrand(), anv.getPrice(), ScreenType::QLED, 1980, 1080, 40.5 };
	Radio r1{ anv.getName(), anv.getBrand(), anv.getPrice(), Tuner::Digital, IsPortable::YES, SuppFreq::DAB };

	std::cout << "Output of data about the derived class via the base class" << std::endl;

	anv_ = &t1;
	std::cout << *anv_;
	anv_ = &r1;
	std::cout << *anv_;

	return 0;
}
