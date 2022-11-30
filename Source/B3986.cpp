// 백준 3986 [스택] 좋은 문자열
#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int num;
	cin >> num;

	int ans = 0;

	stack<char> s;
	for (int i = 0; i < num; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < str.length(); j++){
			if (s.empty() || s.top() != str[j]) s.push(str[j]);
			else if (s.top() == str[j]) s.pop();
		}

		if (s.empty()) ans++;

		while (!s.empty()) s.pop();
	}

	cout << ans;
	return 0;
}