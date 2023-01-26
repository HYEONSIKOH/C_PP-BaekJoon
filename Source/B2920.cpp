// 백준 2920 음계
#include <iostream>
using namespace std;

int main() {
    int arr[8];
    int as = 0, des = 0;
    
    for (int i = 0; i < 8; i++) cin >> arr[i];
    
    for (int i = 0; i < 4; i++) {
        if (arr[i] == i + 1 && arr[i] + arr[7 - i] == 9) as++;
       
        else if (arr[7 - i] == i + 1 && arr[i] + arr[7 - i] == 9) des++;
    }

    if (as == 4) cout << "ascending";
    else if (des == 4) cout << "descending";
    else cout << "mixed";

    return 0;
}