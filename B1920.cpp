// 백준 1920 맵을 이용해서 카드찾기 하기!
#include <iostream>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	map <int, int>arr;

	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		arr[num] = 1;
	}

	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> num;
		if (arr[num]) cout << arr[num] << "\n";
		else cout << 0 << "\n";
	}

	return 0;

}