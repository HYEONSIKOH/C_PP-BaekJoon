// ���� 2293 [DP] �������� ���� ���ϴ� �ݾ��� ���� �� �ִ� ����� �� ���ϱ�...!
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	vector<int> coin(n + 1);
	vector<int> dp(k + 1, 0);
	dp[0] = 1;

	for (int i = 1; i <= n; i++) cin >> coin[i];

	for (int i = 1; i <= n; i++)
		for (int j = coin[i]; j <= k; j++) dp[j] += dp[j - coin[i]];

	cout << dp[k];

	return 0;
}