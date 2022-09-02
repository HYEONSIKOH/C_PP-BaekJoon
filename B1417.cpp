// ���� 1417 [�׸��� �˰���] ������ ������� ��ȸ�ǿ��� ����!
#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	priority_queue<int> q; // �������� �켱���� ť

	int num;
	cin >> num;

	int first, n, count = 0;
	for (int i = 0; i < num; i++) {
		if (i == 0) cin >> first; // ��ȣ 1���� ť���� ����
		else {
			cin >> n;
			q.push(n);
		}
	}
	if (num == 1) {
		cout << 0;
		return 0;
	}
	while (1) {
		if (q.top() < first) break;
		else {
			n = q.top(); // ���� ���� ��ǥ ��
			q.pop();
			n--; // ���� ���� ��ǥ ���� ����� ��ǥ �� ��� �� �Ѹ���,
			first++; // �޵��ְ� �����ϸ�
			count++; // �� ��ǥ���� 1 �����ϰ� ���� ���� ���� 1 ��������.
			q.push(n);
		}
	}

	cout << count;
	return 0;
}