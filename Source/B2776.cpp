// 백준 2776 [MAP,DIC] 원하는 수 찾기
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int num;
    cin >> num;

    for (int i = 0; i < num; i++) {
        int a, b;
        cin >> a;
        map<int, int> t1;
        pair<int, int> p;

        for (int j = 0; j < a; j++) {
            cin >> p.first;
            p.second = 1;

            t1.insert(p);
        }

        cin >> a;
        int n;
        for (int i = 0; i < a; i++) {
            cin >> n;
            if (t1[n] == 1) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
    }

    return 0;
}
