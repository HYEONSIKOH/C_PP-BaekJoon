// ����� �̿��� ������ �ڵ��� ��ü �����
#include <iostream>
#include <string>
using namespace std;

class Car {
	int speed; //�ӵ�

public:
	void setSpeed(int s) { speed = s; }
	int getSpeed() { return speed; }
};

class SportsCar : public Car { // CarŬ������ SportsCar���� ���
	bool turbo;

public:
	void setTurbo(bool newValue) { turbo = newValue; }
	string getTurbo() { if (turbo == true) return "ON"; else return "OFF"; }
};

int main() {
	SportsCar c;

	c.setSpeed(60); // �θ� Ŭ������ �ִ� setSpeed ���
	c.setTurbo(true); // �ڽ� Ŭ������ �ִ� setTurbo ���
	cout << "�ӵ�: " << c.getSpeed() << " �ͺ�: " << c.getTurbo() << "\n";
	
	c.setSpeed(100);
	c.setTurbo(false);
	cout << "�ӵ�: " << c.getSpeed() << " �ͺ�: " << c.getTurbo() << "\n";

	return 0;
}