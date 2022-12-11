// 백준 11000 [큐] 강의실 배정
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct cmp_pq {
	// second 작은 순
	bool operator()(pair<int, int>x, pair<int, int> y) {
		return x.second > y.second;
	}
};

priority_queue<pair<int, int>, vector<pair<int, int>>, cmp_pq > pq;
vector<pair<int, int>> v;
int ans = 0;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int N;
	cin >> N;

	pair<int, int> a;
	for (int i = 0; i < N; i++) {
		cin >> a.first >> a.second;
		v.push_back(a);
	}

	sort(v.begin(), v.end());
	pq.push(v[0]);

	for (int i = 1; i < N; i++) {
		if (v[i].first >= pq.top().second) {
			pq.pop();
			pq.push(v[i]);
		}
		else {
			pq.push(v[i]);
		}
	}

	int ans = pq.size();
	cout << ans << '\n';

	return 0;
}