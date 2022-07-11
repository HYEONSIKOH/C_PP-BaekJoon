// 백준 11650 좌표 내림차순으로 정렬하기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) return a.second < b.second;
	else return a.first < b.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num;
	cin >> num;
	
	vector<pair<int, int>> pos;
	int x, y;

	for (int i = 0; i < num; i++) {
		cin >> x;
		cin >> y;

		pos.push_back(make_pair(x, y));
	}

	sort(pos.begin(), pos.end(), compare);

	for (int i = 0; i < num; i++) cout << pos[i].first << " " << pos[i].second << "\n";
	
	return 0;
}