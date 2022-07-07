#include<iostream>
using namespace std;

int main() {
	// I/O 가속 시 사용, 주로 알고리즘 문제에서만 사용되며, 실무에서는 사용해서는 안댐
	// 이걸 사용하면 C언어의 I/O 명령어를 사용할 수 없다.
	ios_base::sync_with_stdio(false);

	// cin과 cout가 묶어져 있다나 뭐라나...... 이걸 사용해야 c++의 독자적인 버퍼가 생성되고,
	// 그래야 I/O가 빨라진다고 한다나 뭐라나...
	// 이걸 사용하면 C언어의 I/O 명령어를 사용할 수 없다.
	cin.tie(NULL);
	cout.tie(NULL);

	string input;
	int index = -1;
	int n;
	cin >> n; // n을 입력하라는 소리같은데....
	int *s = new int[n]; // 자바랑 같은 형식같음

	for (int i = 0; i < n; i++) {
		cin >> input; // input을 입력하라는 소리같은데....

		if (input == "push") {
			index++;
			cin >> s[index]; // s[index]에 입력
		}

		else if (input == "pop") {
			if (index == -1)cout << index << '\n';
			else {
				cout << s[index] << '\n';
				index--;
			}
		}

		else if (input == "size") cout << index + 1 << '\n';

		else if (input == "empty") {
			if (index == -1)cout << 1 << '\n';
			else cout << 0 << '\n';
		}

		else if (input == "top") {
			if (index == -1)cout << index << '\n';
			else cout << s[index] << '\n';
		}
	}

	delete[] s; // C언어의 FREE와 같은 명령어.
	return 0;
}