// 백준 1449 [그리디 알고리즘] 구멍을 막을 때 필요한 테이프 개수의 촤소를 구해라
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL);

	int num, len;
	cin >> num >> len;
	vector <double> arr(num);

	for (int i = 0; i < num; i++) cin >> arr[i];
	sort(arr.begin(), arr.end());

	int index = 0;
	double temp = arr[0] - 0.5 + len; // 0.5 만큼의 간격이 필요하니까 첫 값에서 0.5.를 빼주고
	int cnt = 0;                      // 거기의 테이프 최대 길이를 구하면 테이프가 닿는 범위가 나온다.
	while (1) {
		if (index == num) {
			cnt++;
			break;
		}

		if (arr[index] < temp) index++;
		else {
			temp = arr[index] - 0.5 + len; // 테이프 범위를 넘겼을 때, 새로운 기준값을 다시 계산해준다.
			cnt++;
		}
	}

	cout << cnt;
	return 0;
}