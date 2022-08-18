//백준 1439 [그리디 알고리즘] 연속된 숫자 카드를 몇번 뒤집어야 같은 숫자들이 될까
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