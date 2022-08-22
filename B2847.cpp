// 백준 2847 [그리디 알고리즘] 오름차순으로 만들려면 1씩 몇번 빼야하는지의 최솟값!
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N,n;
	vector<int> arr;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> n;
		arr.push_back(n);
	}

	int ans = 0;
	for (int i = N - 2; i >= 0; i--) {
		if (arr[i] >= arr[i + 1]) {
			ans += arr[i] - (arr[i + 1] - 1);
			arr[i] = arr[i + 1] - 1;
		}
	}

	cout << ans;
	return 0;
}