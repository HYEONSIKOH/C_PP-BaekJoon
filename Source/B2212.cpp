// 백준 2212 [그리디] USN
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int N, M; // N은 센서, M은 집중국

	cin >> N >> M;
	vector<int> sensor(N);
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < N; i++) cin >> sensor[i];

	sort(sensor.begin(), sensor.end(), greater<int>()); // 내림차순 정렬

	for (int i = 0; i < N - 1; i++) {
		int num = sensor[i] - sensor[i + 1];
		pq.push(num);
	}

	int ans = 0;
	for (int i = 0; i < N - M; i++) {
		ans += pq.top();
		pq.pop();
	}

	cout << ans;
	return 0;
}