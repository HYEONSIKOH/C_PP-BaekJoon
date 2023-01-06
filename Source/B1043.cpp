// ���� 1043 [��������] I'm so sorry, but i love you �� ������~
#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> parent;
vector<vector<int>> party;
vector<int> trust;

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
	party.resize(m);

	int N;
	cin >> N;
	trust.resize(N);
	for (int i = 0; i < N; i++) cin >> trust[i];

	// �ʱ�ȭ
	for (int i = 0; i <= n; i++) parent[i] = i;

	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		party[i].resize(num);

		for (int j = 0; j < num; j++) cin >> party[i][j];
	}

	if (!N) {
		cout << m;
		return 0;
	}

	for (int i = 0; i < m; i++) {
		int k = party[i][0];

		for (int j = 1; j < party[i].size(); j++) Union(k, party[i][j]);
	}

	int ans = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < party[i].size(); j++) {
			bool flag = true;
			for (int k = 0; k < N; k++) {
				if (find(party[i][j]) == find(trust[k])) {
					flag = false;
					ans++;
					break;
				}
			}

			if (!flag) break;
		}
	}

	cout << m - ans;
	return 0;
}