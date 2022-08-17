// 백준 10610 [그리디 알고리즘] 30의 배수 찾기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	string str;
	cin >> str;
	vector<char> arr;

	int sum = 0;
	int count = 0;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '0') count++;
		sum += str[i] - '0';
		arr.push_back(str[i]);
	}
	
	// 3의 배수 조건은 모든 자리의 수 합이 3의 배수여야 한다.
	// 0한개만 있으면 10의 배수로 만들 수 있기 때문에, 3과 10의 최소공배수인 30의 배수조건이 된다. 
	if (sum % 3 == 0 && count != 0) {
		sort(arr.begin(), arr.end(), greater<int>());
		for (auto& e : arr) cout << e;
	}
	else cout << -1;

	return 0;
}