// ���� 1904 ����⸦ ��� ������ �߶� ��� ����Ⱑ �ʿ��ؾ� X�� ����������...
// ã�ƺ��ϱ� ������ ���� �ǹ̰� �־���.
// ���� ����� ���̷� ã�Ƶ� ������, 2������ �ٲ㼭 1�� ������ ã�� ����...;

#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x;
	int count = 0;

	cin >> x;

	while (x > 0) {
		if (x % 2 == 1) count++;
		x /= 2;
	}

	cout << count;
	return 0;
}