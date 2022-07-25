// 백준 14425 숫자대신 문자열로 맵 구성!
#include <iostream>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	map<string, bool> name;

	string s;
	int count = 0;
	for (int i = 0; i < n + m; i++) {
		if (i < n) {
			cin >> s;
			name.insert(make_pair(s, 1));
		}
		else {
			cin >> s;
			if (name.find(s) != name.end()) count++;
		}
	}

	cout << count;
	return 0;
}