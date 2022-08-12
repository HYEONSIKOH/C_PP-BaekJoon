// 백준 25314 진짜 어이없는 문제 ㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋ
#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n/4; i++){
        cout << "long ";
        if(i == n/4 - 1) cout << "int";
    }
}
