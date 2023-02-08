// 백준 10211 [누적합] Maximum Subarray
# include <iostream>
# include <vector>
using namespace std;

int main() {
    int num;
    cin >> num;

    while(num--) {
        int n;
        cin >> n;
        vector<int> vec(n);

        for (int i = 0; i < n; i++) cin >> vec[i];

        int ans = -100000;
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += vec[i];
            ans = max(ans, sum);

            if (sum < 0) sum = 0;
        }

        cout << ans << '\n';
    }

    return 0;
}