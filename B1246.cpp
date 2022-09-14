// ���� 1246 [�׸��� �˰���] ���� �ް������ �ִ��� ���� ���� ����� �ȴ�.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> Egg(M);
	for (int i = 0; i < M; i++) cin >> Egg[i];
	sort(Egg.begin(), Egg.end()); // �ް����� �������� ����

	int Max_Index = 0, Money = 0;

	for (int i = 0; i < M; i++) {
		if ((M - i) > N) { // �������� ������ �ִ� �ް��� ������ �մ��� ������ ���� ��
			if ((N * Egg[i]) > Money) {
				Money = N * Egg[i];
				Max_Index = i;
			}
		}
		else { // �������� ������ �ִ� �ް��� ������ �մ��� ���� ���ų� �� ���� ��!
			if (((M - i) * Egg[i]) > Money) {
				Money = (M - i) * Egg[i];
				Max_Index = i;
			}
		}
	}

	cout << Egg[Max_Index] << " " << Money;
	return 0;
}