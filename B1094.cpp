// 백준 1904 막대기를 계속 반으로 잘라서 몇개의 막대기가 필요해야 X랑 같아지는지...
// 찾아보니까 문제에 숨은 의미가 있었다.
// 물론 막대기 길이로 찾아도 되지만, 2진수로 바꿔서 1의 갯수를 찾는 문제...;

#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x;
	int count = 0;

	cin >> x;

	while (x > 0) {
		if (x % 2 == 1) count++;
		x /= 2;
	}

	cout << count;
	return 0;
}