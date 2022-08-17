// ���� 10610 [�׸��� �˰���] 30�� ��� ã��
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
	
	// 3�� ��� ������ ��� �ڸ��� �� ���� 3�� ������� �Ѵ�.
	// 0�Ѱ��� ������ 10�� ����� ���� �� �ֱ� ������, 3�� 10�� �ּҰ������ 30�� ��������� �ȴ�. 
	if (sum % 3 == 0 && count != 0) {
		sort(arr.begin(), arr.end(), greater<int>());
		for (auto& e : arr) cout << e;
	}
	else cout << -1;

	return 0;
}