#include <iostream>
#include <string>
using namespace std;

class car {
	int speed;
	int gear;
	string color;

public:
	int getSpeed() {
		return speed;
	}
	void setSpeed(int s) {
		speed = s;
	}
};