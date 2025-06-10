#include "TV.h"
#include "Radio.h"

int main() {
	std::cout << "\t\t\tTV PART" << std::endl;

	TV t1, t2;
	std::cout << "Uninitialized variable TV #1: " << t1;
	std::cout << "Uninitialized variable TV #2: " << t2;

	t1.setName("Samsung tech 1");
	t1.setBrand("Samsung");
	t1.setPrice(169000);

	std::cout << t1;

	std::cout << "\t\t\tRadio PART" << std::endl;

	Radio r1, r2;
	std::cout << "Uninitialized variable Radio #1: " << r1;
	std::cout << "Uninitialized variable Radio #2: " << r2;

	r1.setIsPort(IsPortable::YES);
	r1.setSuppFreq(SuppFreq::DAB);
	r1.setTuner(Tuner::Digital);

	std::cout << r1;

	return 0;
}
