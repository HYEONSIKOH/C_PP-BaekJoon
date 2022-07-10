#include "Car.h"
using namespace std;

int main() {
	car myCar;
	myCar.setSpeed(80);
	cout << "현재 속도는 " << myCar.getSpeed() << "km/h \n";

	return 0;
}