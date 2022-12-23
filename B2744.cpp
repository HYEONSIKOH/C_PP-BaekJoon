// 백준 2744 시험기간 스트릭 유지용...
#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string str;
    cin >> str;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'a') str[i] -= 32;
        else str[i] += 32;
    }

    cout << str;
    return 0;
}
