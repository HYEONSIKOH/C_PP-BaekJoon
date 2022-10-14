#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL);
	int num;
	cin >> num;
	int cnt = 0;
	vector<int> v(num + 1, 0);
	int min = 10000000;
	v[1] = 0, v[2] = 1, v[3] = 1;

	for (int i = 4; i < num+1; i++) {
		if (i % 3 == 0) if(min > v[i / 3] + 1) min = v[i / 3] + 1;
		if (i % 2 == 0) if (min > v[i / 2] + 1) min = v[i / 2] + 1;
		if (min > v[i - 1] + 1) min = v[i - 1] + 1;

		v[i] = min;
		min = 10000000;
	}

	cout << v[num];
	return 0;
}