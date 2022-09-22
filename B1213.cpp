// ���� 1213 [�׸��� �˰���] �ⷯ�� ������ ���˺� �ε��� �쿵�� (ȸ�� �����)
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	string str;
	cin >> str;
	int arr[26] = { 0, };
	int a = 0;
	int index = -1;
	string ans = str;

	for (int i = 0; i < str.length(); i++) arr[str[i] - 'A']++;

	for (int i = 0; i < 26; i++)if (arr[i] % 2 == 1) {
		a++;
		index = i;
	}
	// Ȧ���� �ΰ� �̻��̸� ȸ���� ���� �� ����.
	if (a > 1) {
		cout << "I'm Sorry Hansoo";
		return 0;
	}
	// Ȧ�� ���� �Ѱ��� ����� ����ֱ�
	if (index != -1) {
		ans[(str.length() - 1) / 2] = index + 'A';
		arr[index]--;
	}

	// ���̶� �ڿ��� �Ѱ��� ����ֱ�
	int front = 0, back = str.length() - 1;
	for (int i = 0; i < 26; i++) {
		if (front < back) {
			while (arr[i] != 0) {
				ans[front++] = i + 'A';
				ans[back--] = i + 'A';
				arr[i] -= 2;
			}
		}
	}

	cout << ans;
	return 0;
}