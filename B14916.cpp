// ���� 14916 [�׸��� �˰���] 2��,5������ �ּ����� ������ �ܵ��ֱ�!
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int num;
	cin >> num;

	if (num <4 && num != 2) { // �Ž������� ���� �� ���� ���
		cout << -1;
		return 0;
	}

	int coin5 = 0, coin2 = 0;
	if (num % 5 == 0 || num % 5 == 2 || num % 5 == 4) { // �������� ¦��
		coin5 = num / 5;
		num %= 5;
		coin2 = num / 2;
	}
	else { // �������� Ȧ��
		coin5 = (num / 5) - 1;
		num = (num % 5) + 5;
		coin2 = num / 2;
	}

	cout << coin5 + coin2;
	return 0;
}