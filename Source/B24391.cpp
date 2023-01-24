// 백준 24391 [분리집합] 귀찮은 대학생....ㅜㅜ
#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> parent;

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
	vector<int> Class(n);

	// 초기화
	for (int i = 0; i <= n; i++) parent[i] = i;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		Union(a, b);
	}

	for (int i = 0; i < n; i++) cin >> Class[i];

	int cnt = 0;
	for (int i = 0; i < n - 1; i++) {
		if (find(Class[i]) != find(Class[i+1])) 
			cnt++;
	}

	cout << cnt;
	return 0;
}