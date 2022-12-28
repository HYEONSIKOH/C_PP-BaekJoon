// ���� 2212 [�׸���] USN
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int N, M; // N�� ����, M�� ���߱�

	cin >> N >> M;
	vector<int> sensor(N);
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < N; i++) cin >> sensor[i];

	sort(sensor.begin(), sensor.end(), greater<int>()); // �������� ����

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