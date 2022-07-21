// 백준 2309 숫자들의 합이 100인 값만 정렬 후, 출력
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> dwarf;

	int sum = 0;

	for (int i = 0; i < 9; i++) {
		int k;
		cin >> k;

		dwarf.push_back(k);

		sum += k;
	}

	sum -= 100;

	int a, b;

	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (dwarf[i] + dwarf[j] == sum) {
				a = dwarf[i];
				b = dwarf[j];
			}
		}
	}

	sort(dwarf.begin(), dwarf.end());

	for (auto& e : dwarf) if ((e != a) && (e != b)) cout << e << "\n";

	return 0;
}