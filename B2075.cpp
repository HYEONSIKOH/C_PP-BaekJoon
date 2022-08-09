// ���� 2075 [�켱���� ť] N��°�� ū �� ã��!
#include <queue>
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num,n;
	cin >> num;

	priority_queue <int , vector<int>, greater<int>> q;

	for (int i = 0; i < num * num; i++) {
		cin >> n;
		q.push(n);
		if (q.size() > num) q.pop(); // ����� N���� Ŀ���� ���� ���� ���� ������. (��¥�� �׺��� ���� ������ �ʿ� �����ϱ�!)
	}

	cout << q.top(); // �׷��� �켱���� ť�� ��Ʈ����� ���� N��°�� ū��.

	return 0;
}