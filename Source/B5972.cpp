// 백준 5972 [다익스트라] 택배 배송
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 987654321

int N, M, X;
vector< vector<pair<int, int>> > vec;
vector<int> dist;

void dijkstra(int s) {
	dist[s] = 0; // 처음 위치는 0

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq; // 최대힙
	pq.push({ dist[s] , s });

	while (!pq.empty()) {
		int cur = pq.top().second; // 큐의 가장 맨 앞에 있는 정점의 번호를 담아온다.
		int distance = pq.top().first;
		pq.pop();

		if (cur == X) return;

		// 선택한 노드의 모든 인접 노드들을 확인한다.
		for (int i = 0; i < vec[cur].size(); i++) {
			int next = vec[cur][i].first; // 정점
			int nextDistance = distance + vec[cur][i].second; // 비용

			// 다음 것과 기존의 비용과 비교
			if (nextDistance < dist[next]) {
				dist[next] = nextDistance;
				pq.push({ nextDistance , next });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	cin >> N >> M;

	dist.resize(N + 1, INF);
	vec.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int u, v, k;
		cin >> u >> v >> k;
		vec[u].push_back({ v,k });
		vec[v].push_back({ u,k });
	}

	dijkstra(1);

	cout << dist[N];
	return 0;
}
