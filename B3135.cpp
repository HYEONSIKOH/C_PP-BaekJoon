// 백준 3135 [그리디 알고리즘] 라디오 버튼을 최소한으로 누르자
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int num,A,B,n,Hz;
	cin >> A >> B;
	cin >> num;

	int temp = abs(A - B);
	int min = 1000;
	for (int i = 0; i < num; i++) {
		cin >> n;
		Hz = abs(B - n) + 1;
		if (min > Hz) min = Hz;
	}

	if (temp < min) cout << temp;
	else cout << min;

	return 0;
}