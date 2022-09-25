#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
    
    int num;
    cin >> num;
    vector<int> v(num);
    
    for(auto & e : v) cin >> e;
    sort(v.begin(),v.end());
    
    if(num % 2 == 1) cout << v[(num-1)/2];
    else cout << v[(num/2)-1];
    
    return 0;
}
