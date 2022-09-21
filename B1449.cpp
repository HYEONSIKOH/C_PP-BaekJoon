// ���� 1449 [�׸��� �˰���] ������ ���� �� �ʿ��� ������ ������ �ҼҸ� ���ض�
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL);

	int num, len;
	cin >> num >> len;
	vector <double> arr(num);

	for (int i = 0; i < num; i++) cin >> arr[i];
	sort(arr.begin(), arr.end());

	int index = 0;
	double temp = arr[0] - 0.5 + len; // 0.5 ��ŭ�� ������ �ʿ��ϴϱ� ù ������ 0.5.�� ���ְ�
	int cnt = 0;                      // �ű��� ������ �ִ� ���̸� ���ϸ� �������� ��� ������ ���´�.
	while (1) {
		if (index == num) {
			cnt++;
			break;
		}

		if (arr[index] < temp) index++;
		else {
			temp = arr[index] - 0.5 + len; // ������ ������ �Ѱ��� ��, ���ο� ���ذ��� �ٽ� ������ش�.
			cnt++;
		}
	}

	cout << cnt;
	return 0;
}