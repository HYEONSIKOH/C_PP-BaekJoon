// ���� 1543 ���� �ȿ��� �ߺ����� ���� ����ã��!
#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string s;
    string a;
    getline(cin, s); // ������� �������� �̰� ����ؾ� �ϴµ� �ʹ�.
    getline(cin, a);

    int cnt = 0;
    int a_i = 0;
    int num;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == a[a_i]) a_i++;
        else {
            i -= a_i; // string s�� ���� �ε��� ���ڵ� �ٽ� �˻��ؾ� �ϱ� ������ a�� �ε��� ��ŭ ���ش�.
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