// 백준 10184 [stable_sort] 나이순 정렬 (같은 원소일때는 어떻게 해야하는가....)
// 값이 같은 원소의 전후관계가 바뀌지 않는 정렬 알고리즘을 안정 정렬(stable sort)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, string> a, pair<int, string> b) {
	return a.first < b.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num;
	cin >> num;

	vector<pair<int, string>> members;

	int age;
	string name;

	for (int i = 0; i < num; i++) {
		cin >> age >> name;

		members.push_back(make_pair(age, name));
	}

	stable_sort(members.begin(), members.end(), compare);
	//stable_sort : 같은 원소더라도 원래의 순서가 sorting 후에도 유지되는 정렬방식

	for (int i = 0; i < num; i++) cout << members[i].first << " " << members[i].second << "\n";

	return 0;
}