// 백준 1939 [다익스트라] 중량제한...!
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 1000000001

int V, E;
vector<pair<int, int>> vec[100001];
vector<int> dist;

void dijkstra(int K) {
	dist[K] = INF;

	priority_queue<pair<int, int>> pq;
	pq.push({ dist[K] , K });

	while (!pq.empty()) {
		int cur = pq.top().second; // 큐의 가장 맨 앞에 있는 정점의 번호를 담아온다.
		int distance = pq.top().first;
		pq.pop();

		// 이미 담겨 있는 것보다 distance가 작으면 넘어간다.
		if (dist[cur] > distance) continue;

		// 선택한 노드의 모든 인접 노드들을 확인한다.
		for (int i = 0; i < vec[cur].size(); i++) {
			int next = vec[cur][i].first; // 정점
			int nextDistance = min(distance , vec[cur][i].second); // 비용

			// 다음 것과 기존의 비용과 비교
			if (nextDistance > dist[next]) {
				dist[next] = nextDistance;
				pq.push({ nextDistance , next });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	cin >> V >> E;

	dist.resize(V + 1, -1);

	for (int i = 0; i < E; i++) {
		int u, v, k;
		cin >> u >> v >> k;
		vec[u].push_back({ v,k });
		vec[v].push_back({ u,k });
	}

	int start, end;
	cin >> start >> end;

	dijkstra(start);
	
	cout << dist[end];
	return 0;
}