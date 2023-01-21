#include <iostream>
#include <stack>
using namespace std;

int main() {
    int num;
    cin >> num;
    stack<int> s;

    for (int i = 0; i < num; i++) {
        int a;
        cin >> a;

        s.push(a);
    }

    int a = s.top();
    s.pop();

    int ans = 1;
    int size = s.size();
    for (int i = 0; i < size; i++) {
        if (s.top() > a) {
            a = s.top();
            ans++;
        }
        s.pop();
    }

    cout << ans;
    return 0;
}