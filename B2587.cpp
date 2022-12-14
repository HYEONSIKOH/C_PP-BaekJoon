#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v(5);
    int sum = 0;
    
    for(int i = 0; i<5; i++){
        int n;
        cin >> n;
        v[i] = n;
        sum += n;
    }
    
    sort(v.begin(),v.end());
    cout << sum/5 << '\n' << v[2];
    
    return 0;
}
