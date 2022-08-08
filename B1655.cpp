// ���� 1655 [�켱���� ť] ���� �ΰ� �̿��� �߾Ӱ� ã��
// ������ ����������, �� �̷��� �������� �ñ���......
// ������ ����� ������ �Ѱ�
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int num,n;
	int temp_max, temp_min;
	cin >> num;

	priority_queue<int, vector<int>, greater<int>> min; // ���� ������ �ִ� ť
	priority_queue<int> max; // ū ������ �ִ� ť

	// �ּ� ���� ������ �ִ� ���� ���麸�� ������ Ŀ�� ��!
	// �ִ� ���� ũ��� �ּ� �� ũ�⺸�� 1ũ�ų� ����. ==> �ִ� ���� ���� ���� �־�ߴ�

	for (int i = 0; i < num; i++) {
		cin >> n;

		if (max.empty()) max.push(n);

		else {
			if (max.size() == min.size()) max.push(n);

			else min.push(n);

			if (max.top() > min.top()) {
				temp_max = max.top();
				temp_min = max.top();

				max.pop(), min.pop();

				max.push(temp_min);
				min.push(temp_max);
			}
		}

		cout << max.top() << '\n';
	}

	return 0;
}