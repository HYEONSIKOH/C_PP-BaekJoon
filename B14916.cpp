// 백준 14916 [그리디 알고리즘] 2원,5원으로 최소한의 갯수로 잔돈주기!
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int num;
	cin >> num;

	if (num <4 && num != 2) { // 거스름돈을 받을 수 없는 경우
		cout << -1;
		return 0;
	}

	int coin5 = 0, coin2 = 0;
	if (num % 5 == 0 || num % 5 == 2 || num % 5 == 4) { // 나머지가 짝수
		coin5 = num / 5;
		num %= 5;
		coin2 = num / 2;
	}
	else { // 나머지가 홀수
		coin5 = (num / 5) - 1;
		num = (num % 5) + 5;
		coin2 = num / 2;
	}

	cout << coin5 + coin2;
	return 0;
}