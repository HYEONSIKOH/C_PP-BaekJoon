// ���� 17521 [�׸��� �˰���] ��Ʈ�������� �ִ��� �̵��� ������
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	long long num, cash;
	cin >> num >> cash;

	long long n, temp = 0;
	for (int i = 0; i < num; i++) {
		cin >> n;
		if (i == 0 || n < temp) temp = n; // ���� ���� ���� �ԷµǸ�, temp�� ��� �ֽ�ȭ
		else {
			// �Էµ� ���� temp���� ũ�� => ���� 
			// temp������ �����ϰ� n������ �ȰԵǸ� �����ѰŴϱ� �̵��� ����.
			cash = ((cash / temp) * n) + (cash % temp);
			temp = n;
		}
	}

	cout << cash;
	return 0;
}