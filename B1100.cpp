// ���� 1100�� �Ͼ� ĭ���� ���� ��� �ִ°�...?
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	char ch[8][8];
	int count = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> ch[i][j];

			if ((i + j) % 2 == 0 && ch[i][j] == 'F')
				count++;
		}
	}

	cout << count;

	return 0;
}