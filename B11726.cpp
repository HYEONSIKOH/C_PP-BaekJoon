// ���� 11726 [DP] 2xN Ÿ�Ͽ� 2x1 Ÿ���̶� 1x2 Ÿ���� � ����...?
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int num;
	cin >> num;
	int arr[1001];
	arr[1] = 1, arr[2] = 2;

	for (int i = 3; i <= num; i++)
		arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
	
	cout << arr[num];
	return 0;
}