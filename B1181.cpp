// 백준 1181 문자열 길이 순으로 오름차순 정렬
// 벡터(동적배열) 사용
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(string a, string b) {
	if (a.length() != b.length())
		return a.length() < b.length();
	else
		return a < b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<string> str;
	int num;
	cin >> num;

	string temp;

	for (int i = 0; i < num; i++) {
		cin >> temp;
		str.push_back(temp); // 벡터의 입력된 마지막 값 바로 뒤에 입력
	}

	sort(str.begin(), str.end(),compare); // sort(시작 점,끝나는 점,어떤 방식으로 정렬할지)

	for (int i = 0; i < num; i++) {
		if (i == num - 1)cout << str[i];
		else if (str[i] != str[i + 1]) cout << str[i] << "\n";
	}
	
	return 0;
}