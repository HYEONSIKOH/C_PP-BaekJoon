// ���� 18116 [�и�����] �κ� ����!
#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> parent;
vector<int> count_robot;

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
	else {
		parent[x] = y; // ���Ѵ�

		count_robot[y] += count_robot[x];
		count_robot[x] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	cin >> n;
	parent.resize(1000001);
	count_robot.resize(1000001,1);

	// �ʱ�ȭ
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