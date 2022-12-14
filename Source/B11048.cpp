// 백준 11048 [DP] 앞,뒤,대각선 행렬 탐색!
#include <iostream>
#include <vector>
using namespace std;

int N, M;
int arr[1001][1001];
int dp[1001][1001];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M;

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			if (i == 0 || j == 0) {
				arr[i][j] = 0;
				dp[i][j] = 0;
			}
			else cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			int cost = arr[i][j];
			dp[i][j] = max(dp[i][j - 1] + cost, max(dp[i - 1][j] + cost, dp[i - 1][j - 1] + cost));
		}
	}

	cout << dp[N][M];
	return 0;
}