//���� 18870 �ߺ��Ǵ� ��ǥ���� ���� ��, �ڽź��� ���� ��ǥ���� ī�����ϴ� ����
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num;
	cin >> num;

	vector<int> arr;

	int n;
	for (int i = 0; i < num; i++) {
		cin >> n;
		arr.push_back(n);
	}

	vector<int> copy = arr;
	sort(copy.begin(), copy.end());
	copy.erase(unique(copy.begin(), copy.end()), copy.end()); // �ߺ��Ǵ� ���� �����Ѵ�.

	int count = 0;

	// ����Ž���ε� �̰� �� ����Ž������.....
	for (auto&& x : arr) cout << lower_bound(copy.begin(), copy.end(), x) - copy.begin() << ' ';

	return 0;
}