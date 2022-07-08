// 1427 소드인사이드 => 문자열로 받고 정수형 배열로 바꾼 다음, 내림차순 정렬 (버블정렬 이용함)

#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;

	int len = s.length();

	int* arr = new int[len];

	for (int i = 0; i < len; i++) arr[i] = s[i]-'0';

	int temp;

	for (int i = 0; i < len - 1; i++) {
		for (int j = i + 1; j < len; j++) {
			if (arr[i] < arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	for (int i = 0; i < len; i++) cout << arr[i];

	delete[] arr;
	return 0;
	
}