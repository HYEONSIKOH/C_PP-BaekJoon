// 백준 10816 맵을 이용한 같은 카드 개수 구하기 (10815 응용문제)!
#include <iostream>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int num;
	cin >> num;

	map<int,int> card_list;

	int card;
	for (int i = 0; i < num; i++) {
		cin >> card;

		if (card_list.find(card) == card_list.end()) card_list.insert(make_pair(card, 1));
		else ++card_list[card];
	}

	int n;
	cin >> n;

	int find_card;
	for (int i = 0; i < n; i++) {
		cin >> find_card;

		if (card_list.find(find_card) != card_list.end()) cout << card_list[find_card] << " ";
		else cout << 0 << " ";
	}

	return 0;
}