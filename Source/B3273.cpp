// 백준 3273 [투 포인터] 합이 x값인 쌍 찾기!
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	
	int x;
	cin >> x;

	sort(v.begin(), v.end());

	int count = 0;
	int left = 0, right = n - 1;

	while (left < right) {
		int sum = v[left] + v[right];
		
		if (sum == x) {
			++count;
			++left;
			--right;
		}
		
		else if (sum < x) ++left;
		
		else --right;
	}

	cout << count << '\n';
	return 0;
}