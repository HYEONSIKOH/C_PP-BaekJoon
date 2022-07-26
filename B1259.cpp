// 백준 1259 아주 간단한 회문찾기
#include <iostream>
#include <string.h>
using namespace std;

string function(char* str) {
	int len = strlen(str);
	if (len == 1) return "yes";
	else if (len == 2) {
		if (str[0] == str[1]) return "yes";
		else return "no";
	}
	else if (len == 3) {
		if (str[0] == str[2]) return "yes";
		else return "no";
	}
	else if (len == 4) {
		if (str[0] == str[3] && str[1] == str[2]) return "yes";
		else return "no";
	}
	else if (len == 5) {
		if (str[0] == str[4] && str[1] == str[3]) return "yes";
		else return "no";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	char Palindrome[6];
	
	while (1) {
		cin >> Palindrome;
		if (Palindrome[0] == '0') break;
		int len = strlen(Palindrome);
		cout << function(Palindrome) << "\n";
	}

	return 0;
}