// 백준 1789 [그리디 알고리즘] 수들의 합
#include <iostream>
using namespace std;

int main() {
	long long num;
	cin >> num;

	long long a = 1;

	while (1) {
		if ((a * (a + 1)) / 2 > num) break;
		else a++;
	}

	cout << a - 1; // num보다 커지면 a까지의 숫자들 중, 한개만 빼면 num하고 같아진다.
	return 0;
}