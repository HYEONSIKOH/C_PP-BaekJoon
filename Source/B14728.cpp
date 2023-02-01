// 백준 14728 [DP - 타뷸레이션] 벼락치기!
#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> vec;
int dp[101][10001];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int N, T;
	cin >> N >> T;
	vec.resize(N + 1);

	for (int i = 1; i <= N; i++)
		cin >> vec[i].first >> vec[i].second;
	

	for (int i = 1; i <= N; i++) {
		int weight = vec[i].first;
		int value = vec[i].second;

		for (int j = 1; j <= T; j++)
			dp[i][j] = (j >= weight) ? max(dp[i - 1][j], dp[i - 1][j - weight] + value) : dp[i - 1][j];
	}

	cout << dp[N][T];
	return 0;
}