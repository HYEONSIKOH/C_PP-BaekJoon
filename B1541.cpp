// 백준 1541 [그리디 알고리즘] 계산식에 괄호를 넣어서 최소로 만들어보자
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string cal;
	int ans = 0, a = 0;
	vector <int> nums;
	vector <char> mark;
	string num = "";
	bool tf = false;
	cin >> cal;

	for (int i = 0; i < cal.length(); i++) {
		// 부호가 아닌 수는 정수이기 때문에, num으로 저장 후, stoi 사용
		if (cal[i] >= '0' && cal[i] <= '9') num += cal[i];

		// 부호는 cal 벡터에 저장한다.
		else {
			nums.push_back(stoi(num));
			num = "";
			mark.push_back(cal[i]);
		}
	}
	// 마지막 정수도 nums 벡터에 저장한다.
	nums.push_back(stoi(num));

	ans = nums[0];
	for (int i = 1; i < nums.size(); i++) {
		// 첫번째로 - 부호가 나온 뒤로 계속 -를 해주는 이유는
		// 예시로 1-2+3-4+5 => 1 - (2 + 3) - (4 + 5) = 1-  2 - 3 - 4 - 5
		// 괄호가 있는데, 괄호 앞에 -가 있으면 부호가 전부 다 반대로 된다.
		// 괄호는 -뒤에만 생성된다. 예) 1-2+3+4 => 1-(2+3+4)
		if (mark[i - 1] == '-' || tf == true) {
			tf = true;
			ans -= nums[i];
		}
		else ans += nums[i];
	}

	cout << ans;
	return 0;
}