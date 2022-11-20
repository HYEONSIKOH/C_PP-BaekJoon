// ���� 1261 [���ͽ�Ʈ��] ���� � �ν��� ����ұ�....?
#include <iostream>
#include <queue>
using namespace std;
#define INF 987654321

typedef struct {
	int x;
	int y;
}pos;

struct comp {
	bool operator()(pair<int, pos>& a, pair<int, pos>& b) {
		return a.first > b.first;
	}
};

int N, M;
int vec[101][101];
int dist[101][101];

int range(pos p) {
	if (p.x >= 0 && p.y >= 0 && p.x < N && p.y < M) return 1;
	else return 0;
}

int a[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

void dijkstra() {
	dist[0][0] = vec[0][0]; // ó�� ��ġ�� 0

	priority_queue<pair<int, pos>, vector<pair<int, pos>>, comp > pq; // �ִ���
	pq.push({ dist[0][0] , {0,0} });

	while (!pq.empty()) {
		pos cur = pq.top().second;
		int cost = pq.top().first;
		pq.pop();

		if (dist[cur.y][cur.x] < cost) continue;

		// ������ ����� ��� ���� ������ Ȯ���Ѵ�.
		for (int i = 0; i < 4; i++) {
			pos next = { cur.x + a[i][1], cur.y + a[i][0] }; // ����
			if (range(next) == 1) {
				int nextCost = cost + vec[next.y][next.x]; // ���

			// ���� �Ͱ� ������ ���� ��
				if (nextCost < dist[next.y][next.x]) {
					dist[next.y][next.x] = nextCost;
					pq.push({ nextCost , next });
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			vec[i][j] = 0;
			dist[i][j] = INF;
		}
	}

	string str;

	for (int i = 0; i < M; i++) {
		cin >> str;
		for (int j = 0; j < N; j++) vec[i][j] = str[j] - '0';
	}

	dijkstra();

	cout << dist[M - 1][N - 1] << '\n';

	return 0;
}