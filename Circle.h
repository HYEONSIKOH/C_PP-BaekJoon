#include <iostream>
#include <windows.h>
using namespace std;

class Circle {
public:
	int radius, x, y;
	string color;
	// �����ڿ���...?
	Circle(int a=0, int b=0, int r=0) : x(a),y(b),radius(r) { // ����Ʈ �μ� & �ʱ�ȭ ����Ʈ
	}

	void draw() {
		HDC hdc = GetWindowDC(GetForegroundWindow());
		Ellipse(hdc, x - radius, y - radius, x + radius, y + radius);
	}

	void move() {
		x += rand() % 50;
	}
};
