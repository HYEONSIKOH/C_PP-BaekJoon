// ���� 19939 [�׸��� �˰���] ���� ����ŭ ���� �����ϰ� �й�����!
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	int num = ((K * K) + K) / 2; // 1���� K������ ������ ��
	int min = K - 1;

	if (N < num) cout << -1;
	else {
		if ((num - N) % K == 0) cout << min;
		else cout << min+1;
	}
	
	return 0;
}