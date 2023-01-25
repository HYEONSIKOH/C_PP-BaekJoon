// ���� 17250 [��������] ����ö��
#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> parent;
vector<int> galaxy;

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
	galaxy.resize(n + 1);

	for (int i = 1; i <= n; i++) cin >> galaxy[i];

	// �ʱ�ȭ
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