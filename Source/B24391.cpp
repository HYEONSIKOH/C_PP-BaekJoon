// ���� 24391 [�и�����] ������ ���л�....�̤�
#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> parent;

// ��Ʈ ��� ã��
int find(int x) {
	if (x == parent[x]) return x; // ������ ��Ʈ���

	parent[x] = find(parent[x]); // ��ͷ� �θ��� ����
	return parent[x];
}

// ��ġ��
void Union(int x, int y) {
	// �� �θ��带 ��
	x = find(x);
	y = find(y);

	if (x == y) return; // �̹� ���� ����
	else parent[y] = x; // ���Ѵ�
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	cin >> n >> m;
	parent.resize(n + 1);
	vector<int> Class(n);

	// �ʱ�ȭ
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