// 백준 9461 [DP] 삼각형이 나선 모양?!
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int num;
    cin >> num;
    long long arr[101] = { 0, };
    arr[1] = 1, arr[2] = 1, arr[3] = 1, arr[4] = 2, arr[5] = 2;

    int n;
    for (int i = 0; i < num; i++) {
        cin >> n;
        for (int j = 6; j <= n; j++) arr[j] = arr[j - 1] + arr[j - 5];

        cout << arr[n] << '\n';
    }

    return 0;
}
