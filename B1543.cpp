// 백준 1543 문장 안에서 중복없이 같은 문장찾기!
#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string s;
    string a;
    getline(cin, s); // 공백까지 받을려면 이걸 사용해야 하는듯 싶다.
    getline(cin, a);

    int cnt = 0;
    int a_i = 0;
    int num;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == a[a_i]) a_i++;
        else {
            i -= a_i; // string s의 같은 인덱스 문자도 다시 검사해야 하기 때문에 a의 인덱스 만큼 빼준다.
            a_i = 0;
        }
        
        if (a_i == a.length()) {
            cnt++;
            a_i = 0;
        }
        
    }

    cout << cnt;
    return 0;
}