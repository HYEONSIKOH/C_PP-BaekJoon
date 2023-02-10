// 백준 21921 [누적합] 블로그
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> psum(N - M + 2);
    vector<int> vec(N + 1);

    for (int i = 1; i <= N; i++) cin >> vec[i];

    for (int i = 1; i <= M; i++) psum[1] += vec[i];

    int ans = psum[1], cnt = 1;
    for (int i = 2; i < N - M + 2; i++) {
        psum[i] = psum[i - 1] - vec[i - 1] + vec[i + M - 1];

        if (ans == psum[i]) cnt++;
        else {
            if (ans < psum[i]){
                cnt = 1;
                ans = psum[i];
            }
        }
    } 

    if (ans == 0) cout << "SAD";
    else cout << ans << '\n' << cnt;

    return 0;
}
