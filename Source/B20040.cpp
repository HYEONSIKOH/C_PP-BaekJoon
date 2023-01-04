// ���� 20040 [�и�����] ����Ŭ ����!
#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> parent;

// ��Ʈ ��� ã��
int find(int x) {
	if (x == parent[x]) return x; // ������ ��Ʈ���

	return parent[x] = find(parent[x]); // ��ͷ� �θ��� ����
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
	parent.resize(n);

	// �ʱ�ȭ
	for (int i = 0; i < n; i++) parent[i] = i;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		if (find(a) != find(b)) Union(a, b);
		else {
			cout << i + 1;
			return 0;
		}
	}

	cout << 0;
	return 0;
}