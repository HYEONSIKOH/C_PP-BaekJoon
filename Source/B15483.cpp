// 백준 15483 [DP - LCS] 최소 편집
#include <iostream>
#include <vector>
using namespace std;

int dp[1001][1001];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	string a, b;
	cin >> a >> b;

	int a_size = a.length();
	int b_size = b.length();

	for (int i = 0; i <= a_size; i++) dp[0][i] = i;
	for (int i = 0; i <= b_size; i++) dp[i][0] = i;

	for (int i = 1; i <= a_size; i++) {
		for (int j = 1; j <= b_size; j++) {
			
			// a의 i번째 문자와 b의 j번째 문자가 같을 때
			if (a[i-1] == b[j-1]) dp[j][i] = dp[j - 1][i - 1];

			else {
				int case1 = dp[j][i - 1];
				int case2 = dp[j - 1][i];
				int case3 = dp[j - 1][i - 1];

				int Min = min(case1, min(case2, case3));

				dp[j][i] = Min + 1;
			}

		}
	}

	cout << dp[b_size][a_size];
	return 0;
}