#include "Circle.h";
using namespace std;

int main() {
	Circle c1(100,100,50);
	Circle c2(200,200,40);

	for (int i = 0; i < 20; i++) {
		c1.move();
		c1.draw();
		c2.move();
		c2.draw();
		Sleep(1000);
	}

	return 0;
}