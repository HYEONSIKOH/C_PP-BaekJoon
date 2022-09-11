// ���� 1541 [�׸��� �˰���] ���Ŀ� ��ȣ�� �־ �ּҷ� ������
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
		// ��ȣ�� �ƴ� ���� �����̱� ������, num���� ���� ��, stoi ���
		if (cal[i] >= '0' && cal[i] <= '9') num += cal[i];

		// ��ȣ�� cal ���Ϳ� �����Ѵ�.
		else {
			nums.push_back(stoi(num));
			num = "";
			mark.push_back(cal[i]);
		}
	}
	// ������ ������ nums ���Ϳ� �����Ѵ�.
	nums.push_back(stoi(num));

	ans = nums[0];
	for (int i = 1; i < nums.size(); i++) {
		// ù��°�� - ��ȣ�� ���� �ڷ� ��� -�� ���ִ� ������
		// ���÷� 1-2+3-4+5 => 1 - (2 + 3) - (4 + 5) = 1-  2 - 3 - 4 - 5
		// ��ȣ�� �ִµ�, ��ȣ �տ� -�� ������ ��ȣ�� ���� �� �ݴ�� �ȴ�.
		// ��ȣ�� -�ڿ��� �����ȴ�. ��) 1-2+3+4 => 1-(2+3+4)
		if (mark[i - 1] == '-' || tf == true) {
			tf = true;
			ans -= nums[i];
		}
		else ans += nums[i];
	}

	cout << ans;
	return 0;
}