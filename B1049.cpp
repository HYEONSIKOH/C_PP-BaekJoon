// 백준 1049 [그리디 알고리즘] 끊어진 기타줄을 가장 싸게 사는 방법
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	int bundle, piece;
	int b = 1000, p = 1000;
	for (int i = 0; i < M; i++) {
		cin >> bundle >> piece;
		if (b > bundle) b = bundle;
		if (p > piece) p = piece;
	}
	int ans = 0;

	if (b < p * 6) {
		ans += (N / 6) * b;
		ans += (N % 6) * p;
	}
	else ans += N * p;

	if (b * (N / 6 + 1) < ans) ans = b * (N / 6 + 1);
	cout << ans;
	return 0;
}