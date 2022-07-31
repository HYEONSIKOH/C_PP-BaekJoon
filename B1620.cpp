// 백준 1620 맵과 배열을 이용한 포켓몬 도감 만들기!
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int num;
	cin >> num;

	int n;
	cin >> n;

	map<string, int> PocketMon;
	string* PocketMon_arr = new string[num];

	string name;

	for (int i = 0; i < num; i++) {
		cin >> name;
		PocketMon[name] = i + 1; // 몇번째에 있는지 Value값을 찾는 맵 자료구조!
		PocketMon_arr[i] = name; // 몇번째에 무슨 포켓몬이 있는지 찾는 string 배열!
	}

	string search_name;

	for (int i = 0; i < n; i++) {
		cin >> search_name;
		// 인덱스 값으로 찾을때는 맵의 벨류 값으로 키의 값을 찾는 것 보단,
		// 따로 이름만 들어있는 배열을 새로 선언하고 이름값만 따로 저장 한 뒤에, 인덱스로 찾는게
		// 코드 짜기도 쉽고, 소요시간도 적게 걸린다.
		if ('0' <= search_name[0] && search_name[0] <= '9') cout << PocketMon_arr[stoi(search_name)-1] << "\n";
		
		else cout << PocketMon[search_name] << "\n";
		

	}
}