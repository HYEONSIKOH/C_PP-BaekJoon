// 백준 9375 MAP을 이용한 경우의 수 구하는 문제
#include <iostream>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int num;
	cin >> num;

	map<string, int> style; // MAP은 사전처럼 무언가를 찾는거에 적합하다.

	string name, type;

	int n;
	int answer = 1;

	for (int index = 0; index < num; index++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> name >> type;

			if (style.find(type) != style.end()) ++style[type]; // 맵에 같은 타입의 옷이 있는 경우, 개수 증가
			else style.insert(make_pair(type, 1)); // 맵에 같은 타입의 옷이 없는 경우, 타입을 insert하고, 처음이니까 한개로 입력
		}
		for (auto& e : style) answer *= e.second + 1; // 같은 종류의 수만큼 입는거 + 그 종류의 옷을 아예 안입는 경우

		cout << answer - 1 << "\n"; // 1을 빼는 경우 => 모두 다 벗는 경우

		style.clear();
		answer = 1;
	}

	return 0;
}