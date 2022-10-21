// 백준 7562 [그래프 탐색] 나이트의 이동
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int sz;
int ans = 0;
typedef struct {
	int x;
	int y;
}pos;
pos start_pos, end_pos; // 출발위치 , 도착위치

vector<pair<pos, int>> v;
queue<pair<pos, int>> q;

bool visit[301][301]{};

int knight_move[8][2] = { {2,1},{2,-1},{-2,1},{-2,-1},{1,-2},{1,2},{-1,2},{-1,-2} };

int range(pos Pos) {
	if (Pos.x >= 0 && Pos.y >= 0 && Pos.x < sz && Pos.y < sz) return 1;
	else return 0;
}

int equal_pos(pos p1,pos p2) {
	if (p1.x == p2.x && p1.y == p2.y) return 1;
	else return 0;
}

void bfs(pos p) {
	if (equal_pos(start_pos, end_pos) == 1) {
		ans = 0;
		return;
	}

	q.push(pair<pos, int>(p, 0));
	visit[p.y][p.x] = true;

	while (!q.empty()) {
		pos pos_knight = q.front().first;
		int cnt = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			pos next_pos;
			next_pos.x = pos_knight.x + knight_move[i][1];
			next_pos.y = pos_knight.y + knight_move[i][0];

			if (!visit[next_pos.y][next_pos.x] && range(next_pos) == 1 && equal_pos(next_pos, end_pos) == 0) {
				q.push(pair<pos, int>(next_pos, cnt + 1));
				visit[next_pos.y][next_pos.x] = true;
			}

			else if (equal_pos(next_pos, end_pos) == 1) if (ans > (cnt + 1)) ans = cnt + 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int num;
	cin >> num;

	for (int index = 0; index < num; index++) {
		cin >> sz >> start_pos.x >> start_pos.y >> end_pos.x >> end_pos.y;
		ans = sz * sz;

		bfs(start_pos);
		cout << ans << '\n';
		
		for (int i = 0; i < sz; i++)
			for (int j = 0; j < sz; j++) visit[i][j] = false;
	}

	return 0;
}