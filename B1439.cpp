//���� 1439 [�׸��� �˰���] ���ӵ� ���� ī�带 ��� ������� ���� ���ڵ��� �ɱ�
#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	string str;
	cin >> str;

	int count_0 = 0, count_1 = 0;
	int i = 0;
	while (i != str.length()) {
		if (str[i] == '1') {
			while (str[i] == '1') i++;
			count_1++;
		}

		if (str[i] == '0') {
			while (str[i] == '0') i++;
			count_0++;
		}
	}

	if (count_0 > count_1) cout << count_1;
	else cout << count_0;

	return 0;

}