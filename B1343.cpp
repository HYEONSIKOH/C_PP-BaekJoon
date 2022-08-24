// ���� 1343 [�׸��� �˰���] X�� A�� B�� ä���ߵȴ�. (�������̳�) 
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	string str,ans;
	cin >> str;

	int count = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'X') count++;

		if (str[i] == '.' || i == str.length() - 1) {
			if (count % 4 == 0) for (int i = 0; i < count / 4; i++) ans += "AAAA";
			else if (count % 2 == 0) {
				for (int i = 0; i < count / 4; i++) ans += "AAAA";
				ans += "BB";
			}
			else {
				cout << -1;
				return 0;
			}
			if (str[i] == '.') ans += '.';
			count = 0;
		}
	}

	cout << ans;
	return 0;
}