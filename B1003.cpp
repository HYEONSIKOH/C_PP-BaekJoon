#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> v(41,pair<int,int>(0,0));
pair<int, int> fibonacci(int n) {
    if (n == 0) {
        v[0] = pair<int, int>(1, 0);
        return pair<int,int>(1,0);
    }

    else if (n == 1) {
        v[1] = pair<int, int>(0, 1);
        return pair<int, int>(0, 1);
    }

    if (v[n].first != 0 && v[n].second != 0) return v[n];
    else {
        v[n] = pair<int, int>(fibonacci(n - 1).first + fibonacci(n - 2).first, fibonacci(n - 1).second + fibonacci(n - 2).second);
        return v[n];
    };
}

int main() {
    ios_base::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL);

    int num,N;
    cin >> num;
    pair<int, int> a;

    for (int i = 0; i < num; i++) {
        cin >> N;
        a = fibonacci(N);
        cout << a.first << ' ' << a.second << '\n';
    }

    return 0;
}