#include <iostream>
#include <string>
using namespace std;

int main() {
	string N;
	getline(cin, N);

	for (int i = 0; i < N.size() ; i++) {
		cout << N[i];

		if ((i + 1) % 10 == 0) cout << "\n";
	}
    
    return 0;
}
