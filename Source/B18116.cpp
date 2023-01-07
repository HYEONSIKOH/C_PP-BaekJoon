// 백준 18116 [분리집합] 로봇 조립!
#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> parent;
vector<int> count_robot;

// 루트 노드 찾기
int find(int x) {
	if (x == parent[x]) return x; // 같으면 루트노드

	parent[x] = find(parent[x]); // 재귀로 부모노드 접근
	return parent[x];
}

// 합치기
void Union(int x, int y) {
	// 각 부모노드를 비교
	x = find(x);
	y = find(y);

	if (x == y) return; // 이미 같은 집합
	else {
		parent[x] = y; // 합한다

		count_robot[y] += count_robot[x];
		count_robot[x] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	cin >> n;
	parent.resize(1000001);
	count_robot.resize(1000001,1);

	// 초기화
	for (int i = 0; i <= 1000000; i++) parent[i] = i;

	char ch;
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> ch;

		if (ch == 'I') {
			cin >> a >> b;
			Union(a, b);
		}
		else {
			cin >> a;
			cout << count_robot[find(a)] << '\n';
		}
	}

	return 0;
}