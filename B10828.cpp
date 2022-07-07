#include<iostream>
using namespace std;

int main() {
	// I/O ���� �� ���, �ַ� �˰��� ���������� ���Ǹ�, �ǹ������� ����ؼ��� �ȴ�
	// �̰� ����ϸ� C����� I/O ��ɾ ����� �� ����.
	ios_base::sync_with_stdio(false);

	// cin�� cout�� ������ �ִٳ� ����...... �̰� ����ؾ� c++�� �������� ���۰� �����ǰ�,
	// �׷��� I/O�� �������ٰ� �Ѵٳ� ����...
	// �̰� ����ϸ� C����� I/O ��ɾ ����� �� ����.
	cin.tie(NULL);
	cout.tie(NULL);

	string input;
	int index = -1;
	int n;
	cin >> n; // n�� �Է��϶�� �Ҹ�������....
	int *s = new int[n]; // �ڹٶ� ���� ���İ���

	for (int i = 0; i < n; i++) {
		cin >> input; // input�� �Է��϶�� �Ҹ�������....

		if (input == "push") {
			index++;
			cin >> s[index]; // s[index]�� �Է�
		}

		else if (input == "pop") {
			if (index == -1)cout << index << '\n';
			else {
				cout << s[index] << '\n';
				index--;
			}
		}

		else if (input == "size") cout << index + 1 << '\n';

		else if (input == "empty") {
			if (index == -1)cout << 1 << '\n';
			else cout << 0 << '\n';
		}

		else if (input == "top") {
			if (index == -1)cout << index << '\n';
			else cout << s[index] << '\n';
		}
	}

	delete[] s; // C����� FREE�� ���� ��ɾ�.
	return 0;
}