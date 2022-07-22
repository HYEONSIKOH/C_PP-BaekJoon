// ���� 9375 MAP�� �̿��� ����� �� ���ϴ� ����
#include <iostream>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int num;
	cin >> num;

	map<string, int> style; // MAP�� ����ó�� ���𰡸� ã�°ſ� �����ϴ�.

	string name, type;

	int n;
	int answer = 1;

	for (int index = 0; index < num; index++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> name >> type;

			if (style.find(type) != style.end()) ++style[type]; // �ʿ� ���� Ÿ���� ���� �ִ� ���, ���� ����
			else style.insert(make_pair(type, 1)); // �ʿ� ���� Ÿ���� ���� ���� ���, Ÿ���� insert�ϰ�, ó���̴ϱ� �Ѱ��� �Է�
		}
		for (auto& e : style) answer *= e.second + 1; // ���� ������ ����ŭ �Դ°� + �� ������ ���� �ƿ� ���Դ� ���

		cout << answer - 1 << "\n"; // 1�� ���� ��� => ��� �� ���� ���

		style.clear();
		answer = 1;
	}

	return 0;
}