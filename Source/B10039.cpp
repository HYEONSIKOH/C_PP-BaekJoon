#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> vec(5);
    int sum = 0;
    
    for(int i = 0; i<5; i++){
        cin >> vec[i];
        
        if(vec[i] < 40) vec[i] = 40;
        sum += vec[i];
    }
    
    cout << sum / 5;
    return 0;
}