// ���� 16953 [�׸��� �˰���] ���� ��ȯ�ϱ�
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	long long A, B;
	cin >> A >> B;

	int count = 0;
	while (1) {
		if (B % 10 == 1) {
			B--;
			B /= 10;
			count++;
		}

		else {
			if (B % 2 == 1) { // Ȧ���� ���� ������ �ȴ�!
				cout << -1;
				return 0;
			}
			B /= 2;
			count++;
		}

		if (A == B) { // A�� B�� ������ ���� ���ϴ� ���̱� ������ count�� ���
			count++;
			cout << count;
			return 0;
		}
		else if (A > B) { // B�� A���� �۾����� ���� ���ϴ� ���� �ȳ����� ������, -1�� ���
			cout << -1;
			return 0;
		}
	}
}