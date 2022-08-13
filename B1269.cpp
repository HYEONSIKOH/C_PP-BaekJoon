// 백준 1269 대칭 차집합 찾기 (A + B − 2(A ∩ B) 이용....
#include <iostream>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map<int, int> arr; // 이놈때문에 고생했다... 1억 범위를 내가 어케 만드냐...

	int a, b;
	cin >> a >> b;

	int n;
	for (int i = 0; i < a; i++) {
		cin >> n;
		arr[n] = 1;
	}

	int count = 0; // a와 b의 교집합
	for (int i = 0; i < b; i++) {
		cin >> n;
		if (arr[n] == 1) count++;
	}

	int ans = a + b - (2 * count);
	cout << ans;

	return 0;
}