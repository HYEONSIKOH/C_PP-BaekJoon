// ﻿백준 1309 [DP] 동물원
#include <iostream>
#define mod 9901
using namespace std;

int dp[100000][3];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int n;
	cin >> n;

	dp[0][0] = dp[0][1] = dp[0][2] = 1;

	for (int i = 1; i < n; i++) {
		dp[i][0] = (dp[i - 1][1] % mod) + (dp[i - 1][2] % mod);
		dp[i][1] = (dp[i - 1][0] % mod) + (dp[i - 1][2] % mod);
		dp[i][2] = (dp[i - 1][0] % mod) + (dp[i - 1][1] % mod) + (dp[i - 1][2] % mod);

		dp[i][0] %= mod;
		dp[i][1] %= mod;
		dp[i][2] %= mod;
	}

	int ans = 0;
	for (int i = 0; i < 3; i++) ans += dp[n - 1][i] % mod;

	cout << ans % mod;
	return 0;
}