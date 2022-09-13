// 백준 19939 [그리디 알고리즘] 팀의 수만큼 공을 적절하게 분배하자!
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	int num = ((K * K) + K) / 2; // 1부터 K까지의 수열의 합
	int min = K - 1;

	if (N < num) cout << -1;
	else {
		if ((num - N) % K == 0) cout << min;
		else cout << min+1;
	}
	
	return 0;
}