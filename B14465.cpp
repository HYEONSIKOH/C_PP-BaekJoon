// 백준 14465 [누적합] 소가 길을 건너간 이유 5
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K, B;
    cin >> N >> K >> B;

    vector<int> vec(N + 1, 1);
    vector<int> psum(N - K + 2);

    for (int i = 1; i <= B; i++) {
        int n;
        cin >> n;

        vec[n] = 0;
    }

    for (int i = 1; i <= K; i++) psum[1] += vec[i];
    
    int ans = K - psum[1];
    for (int i = 2; i < N - K + 2; i++) {
        psum[i] = psum[i - 1] - vec[i - 1] + vec[i - 1 + K];

        ans = min(ans, K - psum[i]);
    }

    cout << ans;
    return 0;
}
