// ���� 24416 [���̳��� ���α׷���] �Ǻ���ġ ����..
#include <iostream>
using namespace std;

int cnt = 0;

int fib(int n) {
	if (n == 1 || n == 2) {return 1; }
	else return (fib(n - 1) + fib(n - 2));
}

int main() {
	int num;
	cin >> num;
	int ans;

	if (num == 1 || num == 2) ans = 1;
	else ans = num - 2;

	cout << fib(num) << ' ' << ans;
	return 0;
}