// 백준 13900 [누적합] 순서쌍의 곱의 합
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int N;
    cin >> N;

    vector<long long> vec(N + 1);
    vector<long long> bsum(N + 1);

    for (int i = 1; i <= N; i++) cin >> vec[i];

    for (int i = 1; i <= N; i++) 
        bsum[i] = bsum[i - 1] + vec[N - (i - 1)];

    long long ans = 0;
    for (int i = 1; i < N; i++)
        ans += vec[i] * bsum[N - i];
    
    cout << ans;
    return 0;
}