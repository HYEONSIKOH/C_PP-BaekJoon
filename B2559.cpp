// 백준 2559 [누적합] 수열
#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> vec(N + 1);

    for (int i = 1; i <= N; i++) cin >> vec[i];

    int num = 0;
    for (int i = 1; i <= K; i++) num += vec[i];

    int ans = num;
    for (int i = 2; i <= N - K + 1; i++) {
        num = num - vec[i - 1] + vec[i - 1 + K];

        ans = max(ans, num);
    }

    cout << ans;
    return 0;
}