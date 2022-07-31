// ���� 1620 �ʰ� �迭�� �̿��� ���ϸ� ���� �����!
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
		PocketMon[name] = i + 1; // ���°�� �ִ��� Value���� ã�� �� �ڷᱸ��!
		PocketMon_arr[i] = name; // ���°�� ���� ���ϸ��� �ִ��� ã�� string �迭!
	}

	string search_name;

	for (int i = 0; i < n; i++) {
		cin >> search_name;
		// �ε��� ������ ã������ ���� ���� ������ Ű�� ���� ã�� �� ����,
		// ���� �̸��� ����ִ� �迭�� ���� �����ϰ� �̸����� ���� ���� �� �ڿ�, �ε����� ã�°�
		// �ڵ� ¥�⵵ ����, �ҿ�ð��� ���� �ɸ���.
		if ('0' <= search_name[0] && search_name[0] <= '9') cout << PocketMon_arr[stoi(search_name)-1] << "\n";
		
		else cout << PocketMon[search_name] << "\n";
		

	}
}