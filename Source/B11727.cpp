// 백준 11727 [DP] (2xn) 타일링2
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int num;
    cin >> num;

    vector<int> dp(num + 1);

    for (int i = 1; i <= num; i++) {
        if (i == 1) dp[1] = 1;
        else if (i == 2) dp[2] = 3;
        else if (i == 3) dp[3] = 5;

        else dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 2]) % 10007;
    }

    cout << dp[num] % 10007;
    return 0;
}