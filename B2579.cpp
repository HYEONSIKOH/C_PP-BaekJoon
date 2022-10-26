// 백준 2579 [DP] 계단을 효율적으로 올라가는 법
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int num;
    cin >> num;

    vector<int> stairs(num + 1);
    for (int i = 1; i <= num; i++) cin >> stairs[i];

    vector<int> dp(num + 1, 0);
    dp[1] = stairs[1];
    for (int i = 2; i <= num; i++) {
        dp[i] = max(dp[i - 2], dp[i - 3] + stairs[i - 1]);
        dp[i] += stairs[i];
    }

    cout << dp[num];
    return 0;
}
