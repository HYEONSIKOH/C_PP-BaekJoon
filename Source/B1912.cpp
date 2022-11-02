// 백준 1912 [DP] 연속된 숫자들의 합 중, 가장 큰 값
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int num;
	cin >> num;

	vector<int> dp(num, 0);
	vector<int> number(num, 0);

	for (int i = 0; i < num; i++) cin >> number[i];

	dp[0] = number[0];
	for (int i = 1; i < num; i++)
		dp[i] = max(number[i], dp[i - 1] + number[i]);

	int max = dp[0];
	for (auto& e : dp) if (max < e) max = e;

	cout << max;
	return 0;
}