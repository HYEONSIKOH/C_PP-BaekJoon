// 백준 17521 [그리디 알고리즘] 비트코인으로 최대한 이득을 취하자
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	long long num, cash;
	cin >> num >> cash;

	long long n, temp = 0;
	for (int i = 0; i < num; i++) {
		cin >> n;
		if (i == 0 || n < temp) temp = n; // 만약 작은 수가 입력되면, temp가 계속 최신화
		else {
			// 입력된 수가 temp보다 크다 => 떡상 
			// temp원에서 구매하고 n원에서 팔게되면 떡상한거니까 이득을 본다.
			cash = ((cash / temp) * n) + (cash % temp);
			temp = n;
		}
	}

	cout << cash;
	return 0;
}