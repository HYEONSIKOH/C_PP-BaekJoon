// ���� 1789 [�׸��� �˰���] ������ ��
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

	cout << a - 1; // num���� Ŀ���� a������ ���ڵ� ��, �Ѱ��� ���� num�ϰ� ��������.
	return 0;
}