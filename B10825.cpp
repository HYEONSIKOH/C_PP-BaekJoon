// 백준 10825 [정렬] 여러가지 기준으로 정렬하는 법!
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(pair<string, vector<int>>a, pair<string, vector<int>>b) {
	if (a.second[0] == b.second[0] && a.second[1] == b.second[1] && a.second[2] == b.second[2]) return a.first < b.first;
	else if (a.second[0] == b.second[0] && a.second[1] == b.second[1]) return a.second[2] > b.second[2];
	else if (a.second[0] == b.second[0]) return a.second[1] < b.second[1];
	else return a.second[0] > b.second[0];
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int num;
	cin >> num;

	vector <pair< string, vector<int> >> arr(num);
	int eng, math, lang;

	for (int i = 0; i < num; i++) {
		cin >> arr[i].first >> lang >> eng >> math;
		arr[i].second.push_back(lang);
		arr[i].second.push_back(eng);
		arr[i].second.push_back(math);
	}

	sort(arr.begin(), arr.end(), cmp);

	for (auto& e : arr) cout << e.first << '\n';

	return 0;
}