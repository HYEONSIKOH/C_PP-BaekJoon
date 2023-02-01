// 백준 11659 [누적합] 구간 합 구하기 4
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> vec(N + 1);
	vector<int> psum(N + 1);

	for (int i = 1; i <= N; i++) cin >> vec[i];

	for (int i = 1; i <= N; i++) psum[i] = psum[i - 1] + vec[i];

	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;

		cout << psum[b] - psum[a - 1] << '\n';
	}

	return 0;
}