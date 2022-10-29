// ���� 2294 [���̳��� ���α׷���] �ƴ� �׳� ���� �غ��� ���� �� ������ ��Ű��?
#include <iostream>
#include<cstring>
using namespace std;

int coin[101] = { 0, };
int dp[10001];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	memset(dp, 10001, sizeof(dp));

	for (int i = 1; i <= n; i++) cin >> coin[i];
	
	for (int i = 1; i <= n; i++) {
		if (coin[i] <= k) {
			dp[coin[i]] = 1;
			for (int j = coin[i]; j <= k; j++) dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}

	if (dp[k] > 10000) cout << -1;
	else cout << dp[k];
	return 0;
}