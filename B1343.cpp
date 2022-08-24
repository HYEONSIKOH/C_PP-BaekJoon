// 백준 1343 [그리디 알고리즘] X를 A와 B로 채워야된다. (폴리오미노) 
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