// 백준 11660 [누적합] 구간 합 구하기 5
#include <iostream>
#include <vector>
using namespace std;

// int arr[1025][1025];
int psum[1025][1025];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int N, M, num;

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> num;
			psum[i][j] = psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1] + num;
		}
	}

	for (int i = 1; i <= M; i++) {
		int x1, y1, x2, y2;
		cin >> y1 >> x1 >> y2 >> x2;

		int ans = psum[y2][x2] - psum[y1 - 1][x2] - psum[y2][x1 - 1] + psum[y1 - 1][x1 - 1];
		cout << ans << '\n';
	}

	return 0;
}