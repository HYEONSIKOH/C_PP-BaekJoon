// ���� 20044 [�׸��� �˰���] ������ �Ƿµ��� �ڵ� ����
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
	vector<int> arr(num*2);

	for (int i = 0; i < num * 2; i++) cin >> arr[i];

	sort(arr.begin(), arr.end());

	int a = 200000;
	for (int i = 0; i < num*2; i++) {
		a = min(a, arr[i] + arr[(num*2) - i - 1]);
	}
	cout << a;
	return 0;
}