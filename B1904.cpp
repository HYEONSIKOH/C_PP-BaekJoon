// 백준 1904 [DP] 동주가 타일을 00으로 만들어서 곤란해졌다.
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int num;
	cin >> num;
	vector<int> arr(num+1, 0);
	arr[1] = 1, arr[2] = 2;

	for (int i = 3; i <= num; i++) arr[i] = (arr[i - 1] % 15746) + (arr[i - 2] % 15746);
	
	cout << arr[num] % 15746;
	return 0;
}