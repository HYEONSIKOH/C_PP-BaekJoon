// ���� 1181 ���ڿ� ���� ������ �������� ����
// ����(�����迭) ���
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(string a, string b) {
	if (a.length() != b.length())
		return a.length() < b.length();
	else
		return a < b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<string> str;
	int num;
	cin >> num;

	string temp;

	for (int i = 0; i < num; i++) {
		cin >> temp;
		str.push_back(temp); // ������ �Էµ� ������ �� �ٷ� �ڿ� �Է�
	}

	sort(str.begin(), str.end(),compare); // sort(���� ��,������ ��,� ������� ��������)

	for (int i = 0; i < num; i++) {
		if (i == num - 1)cout << str[i];
		else if (str[i] != str[i + 1]) cout << str[i] << "\n";
	}
	
	return 0;
}