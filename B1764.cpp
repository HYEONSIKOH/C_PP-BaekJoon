// 백준 1764 맵 + 벡터를 이용한 듣보잡 찾아내기!
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	int n , k;
	cin >> n >> k;

	vector<string> a2;
	map<string, int>  a1;;

	string name;
	for (int i = 0; i < n; i++) {
		cin >> name;
		a1[name] = 1;
	}

	for (int i = 0; i < k; i++) {
		cin >> name;
		if (a1[name]) a2.push_back(name);
	}
	sort(a2.begin(), a2.end());

	cout << a2.size() << "\n";
	for (auto& e : a2)  cout << e << endl;
	
	return 0;
}