// 백준 11411 [누적합] 합 구하기
#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int N, K;
    cin >> N;

    vector<int> psum(N+1);

    for(int i = 1; i<=N; i++){
        int num;
        cin >> num;
        psum[i] = psum[i-1] + num;
    }

    cin >> K;
    for(int i = 1; i<=K; i++){
        int a,b;
        cin >> a >> b;

        cout << psum[b] - psum[a-1] << '\n';
    }

    return 0;
}