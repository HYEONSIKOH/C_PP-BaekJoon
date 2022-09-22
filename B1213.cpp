// 백준 1213 [그리디 알고리즘] 기러기 스위스 별똥별 인도인 우영우 (회문 만들기)
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	string str;
	cin >> str;
	int arr[26] = { 0, };
	int a = 0;
	int index = -1;
	string ans = str;

	for (int i = 0; i < str.length(); i++) arr[str[i] - 'A']++;

	for (int i = 0; i < 26; i++)if (arr[i] % 2 == 1) {
		a++;
		index = i;
	}
	// 홀수가 두개 이상이면 회문을 만들 수 없다.
	if (a > 1) {
		cout << "I'm Sorry Hansoo";
		return 0;
	}
	// 홀수 문자 한개만 가운데에 집어넣기
	if (index != -1) {
		ans[(str.length() - 1) / 2] = index + 'A';
		arr[index]--;
	}

	// 앞이랑 뒤에서 한개씩 집어넣기
	int front = 0, back = str.length() - 1;
	for (int i = 0; i < 26; i++) {
		if (front < back) {
			while (arr[i] != 0) {
				ans[front++] = i + 'A';
				ans[back--] = i + 'A';
				arr[i] -= 2;
			}
		}
	}

	cout << ans;
	return 0;
}