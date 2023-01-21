// ���� 17352 [�и�����] �������� �ٸ��� �Ǿ� �帮�ڽ��ϴ�~!
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

	cin >> n;
	parent.resize(n + 1);

	if (n == 2) {
		cout << 1 << ' ' << 2;
		return 0;
	}

	// �ʱ�ȭ
	for (int i = 0; i <= n; i++) parent[i] = i;

	for (int i = 0; i < n - 2; i++) {
		int a, b;
		cin >> a >> b;
		Union(a, b);
	}

	for (int i = 1; i <= n - 1; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (find(i) != find(j)) {
				cout << i << ' ' << j;
				return 0;
			}
		}
	}



	return 0;
}