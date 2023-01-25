// 백준 17250 [분할집합] 은하철도
#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> parent;
vector<int> galaxy;

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
	else parent[y] = x; // 합한다
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	cin >> n >> m;
	parent.resize(n + 1);
	galaxy.resize(n + 1);

	for (int i = 1; i <= n; i++) cin >> galaxy[i];

	// 초기화
	for (int i = 0; i <= n; i++) parent[i] = i;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		int x = find(a);
		int y = find(b);
		
		Union(a, b);
		
		if (x != y) galaxy[find(a)] += galaxy[y];

		cout << galaxy[find(a)] << '\n';
	}

	return 0;
}