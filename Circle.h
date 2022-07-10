#include <iostream>
#include <windows.h>
using namespace std;

class Circle {
public:
	int radius, x, y;
	string color;
	// 생성자였나...?
	Circle(int a=0, int b=0, int r=0) : x(a),y(b),radius(r) { // 디폴트 인수 & 초기화 리스트
	}

	void draw() {
		HDC hdc = GetWindowDC(GetForegroundWindow());
		Ellipse(hdc, x - radius, y - radius, x + radius, y + radius);
	}

	void move() {
		x += rand() % 50;
	}
};
