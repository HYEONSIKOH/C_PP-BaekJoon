#include <iostream>
using namespace std;

int main(){
    int a,b,c,d,e;
    cin >> a >> b >> c >> d >> e;
    
    int sum = a*a + b*b + c*c + d*d + e*e;
    
    cout << sum%10;
    return 0;
}
