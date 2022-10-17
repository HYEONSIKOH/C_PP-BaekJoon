// 백준 9095 [DP] 1,2,3을 여러번 사용하여 원하는 숫자 만들기!
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int num;
	cin >> num;
	int arr[12] = { 0, };
	arr[1] = 1, arr[2] = 2, arr[3] = 4;

	int a;
	for (int index = 0; index < num; index++) {
		cin >> a;
		for (int i = 4; i <= a; i++) {
			if (arr[i] == 0) {
				for (int j = 1; j < 4; j++)
					arr[i] += arr[i - j];
			}
		}

		cout << arr[a] << '\n';
	}

	return 0;
}