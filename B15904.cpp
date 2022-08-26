// 백준 15904 UCPC의 약자가 되는 경우의 수!
#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	string s, a;
	getline(cin, s);

	int count = 0;

	for (int i = 0; i < s.length(); i++) {
		if (count == 0 && s[i] == 'U') count++;
		if (count == 1 && s[i] == 'C') count++;
		if (count == 2 && s[i] == 'P') count++;
		if (count == 3 && s[i] == 'C') count++;
	}

	if (count == 4) cout << "I love UCPC";
	else cout << "I hate UCPC";

	return 0;
}