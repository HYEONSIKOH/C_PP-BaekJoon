// 백준 16953 [그리디 알고리즘] 숫자 변환하기
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	long long A, B;
	cin >> A >> B;

	int count = 0;
	while (1) {
		if (B % 10 == 1) {
			B--;
			B /= 10;
			count++;
		}

		else {
			if (B % 2 == 1) { // 홀수일 경우는 무조건 안댐!
				cout << -1;
				return 0;
			}
			B /= 2;
			count++;
		}

		if (A == B) { // A랑 B가 같으면 내가 원하는 값이기 때문에 count를 출력
			count++;
			cout << count;
			return 0;
		}
		else if (A > B) { // B가 A보다 작아지면 내가 원하는 값이 안나오기 때문에, -1를 출력
			cout << -1;
			return 0;
		}
	}
}
