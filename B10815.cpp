// 백준 10815 맵을 이용한 카드 찾기 문제!
#include <iostream>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);

	int num;
	cin >> num;

	map<int,bool> card_list;

	int card;
	for (int i = 0; i < num; i++) {
		cin >> card;
		card_list.insert(make_pair(card, true));
	}

	int n;
	cin >> n;

	int find_card;
	for (int i = 0; i < n; i++) {
		cin >> find_card;
		if (card_list.find(find_card) == card_list.end()) cout << 0 << " ";
		else cout << 1 << " ";
	}

	return 0;
}