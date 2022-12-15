#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, c, num, cnt = 0;
    cin >> n >> c;
    vector<int> arr (c+1,0);
    
    for(int i = n; i>0; i--){
        cin >> num;
       
        for(int j = 1; num * j <= c; j++)
            arr[num*j]++; 
    }
        
    for(int i = 0; i<=c; i++) if(arr[i] != 0) cnt++;
        
    cout << cnt;
    return 0;
}
