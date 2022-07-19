// ���� 10184 [stable_sort] ���̼� ���� (���� �����϶��� ��� �ؾ��ϴ°�....)
// ���� ���� ������ ���İ��谡 �ٲ��� �ʴ� ���� �˰����� ���� ����(stable sort)
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
	//stable_sort : ���� ���Ҵ��� ������ ������ sorting �Ŀ��� �����Ǵ� ���Ĺ��

	for (int i = 0; i < num; i++) cout << members[i].first << " " << members[i].second << "\n";

	return 0;
}