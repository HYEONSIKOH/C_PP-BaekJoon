#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int cnt = 1;
	string s;
	
    while (getline(cin, s)) {
		if (s == "Was it a cat I saw?") break;
		
		for (int i = 0; i < s.size(); i += cnt + 1) cout << s[i];
		
		cout << "\n";
		cnt++;
	}
    
	return 0;
}
