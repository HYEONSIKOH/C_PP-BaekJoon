// ���� 5972 [���ͽ�Ʈ��] �ù� ���
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 987654321

int N, M, X;
vector< vector<pair<int, int>> > vec;
vector<int> dist;

void dijkstra(int s) {
	dist[s] = 0; // ó�� ��ġ�� 0

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq; // �ִ���
	pq.push({ dist[s] , s });

	while (!pq.empty()) {
		int cur = pq.top().second; // ť�� ���� �� �տ� �ִ� ������ ��ȣ�� ��ƿ´�.
		int distance = pq.top().first;
		pq.pop();

		if (cur == X) return;

		// ������ ����� ��� ���� ������ Ȯ���Ѵ�.
		for (int i = 0; i < vec[cur].size(); i++) {
			int next = vec[cur][i].first; // ����
			int nextDistance = distance + vec[cur][i].second; // ���

			// ���� �Ͱ� ������ ���� ��
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
