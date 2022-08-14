// 백준 11478 문자열 자르기 + 집합(set)을 이용한 중복 문자열 제거!
#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);

	string str,temp;
	set<string> arr; // 집합은 중복을 허용하지 않는다.
	cin >> str;
	int size = str.length();

	for (int i = 0; i < str.length(); i++) {
		for (int j = size; j > 0; j--) {
			// 인덱스 i부터 j만큼의 길이를 잘라낸다
			// ex) 0,1이면 0번째 인덱스부터 1만큼 잘라내는 거니까 0번째 인덱스 값만 나오게 된다!
			temp = str.substr(i, j);
			arr.insert(temp);
		}
		size--;
	}

	cout << arr.size();
	return 0;
}