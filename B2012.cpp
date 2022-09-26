// 백준 2012 [그리디 알고리즘] 정렬 문제임 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int num;
	long long ans = 0;
	cin >> num;
	vector<long long> v(num);

	for (int i = 0; i < num; i++) cin >> v[i];
	sort(v.begin(), v.end());

	for (int i = 1; i <= num; i++) ans += abs(v[i - 1] - i);

	cout << ans;
	return 0;
}