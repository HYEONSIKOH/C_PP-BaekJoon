// 백준 11724 [그래프 탐색] 연결 요소의 개수 구하기!
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

vector<vector<int>> v;
int N, M;
int cnt = 0;
queue<int> q;
vector<bool> visit;

void dfs(int node) {
	visit[node] = true;
	for (int i = 0; i < v[node].size(); i++)
		if (!visit[v[node][i]]) dfs(v[node][i]);
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	cin >> N >> M;
	v.resize(N+1);
	visit.resize(N + 1,false);

	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		if (!visit[i]) {
			dfs(i);
			cnt++;
		}
	}

	cout << cnt;
	return 0;
}