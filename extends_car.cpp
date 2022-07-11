// 상속을 이용한 간단한 자동차 객체 만들기
#include <iostream>
#include <string>
using namespace std;

class Car {
	int speed; //속도

public:
	void setSpeed(int s) { speed = s; }
	int getSpeed() { return speed; }
};

class SportsCar : public Car { // Car클래스를 SportsCar한테 상속
	bool turbo;

public:
	void setTurbo(bool newValue) { turbo = newValue; }
	string getTurbo() { if (turbo == true) return "ON"; else return "OFF"; }
};

int main() {
	SportsCar c;

	c.setSpeed(60); // 부모 클래스에 있는 setSpeed 사용
	c.setTurbo(true); // 자식 클래스에 있는 setTurbo 사용
	cout << "속도: " << c.getSpeed() << " 터보: " << c.getTurbo() << "\n";
	
	c.setSpeed(100);
	c.setTurbo(false);
	cout << "속도: " << c.getSpeed() << " 터보: " << c.getTurbo() << "\n";

	return 0;
}