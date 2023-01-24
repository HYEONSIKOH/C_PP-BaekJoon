// ���� 1939 [���ͽ�Ʈ��] �߷�����...!
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
		int cur = pq.top().second; // ť�� ���� �� �տ� �ִ� ������ ��ȣ�� ��ƿ´�.
		int distance = pq.top().first;
		pq.pop();

		// �̹� ��� �ִ� �ͺ��� distance�� ������ �Ѿ��.
		if (dist[cur] > distance) continue;

		// ������ ����� ��� ���� ������ Ȯ���Ѵ�.
		for (int i = 0; i < vec[cur].size(); i++) {
			int next = vec[cur][i].first; // ����
			int nextDistance = min(distance , vec[cur][i].second); // ���

			// ���� �Ͱ� ������ ���� ��
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