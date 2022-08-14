// ���� 11478 ���ڿ� �ڸ��� + ����(set)�� �̿��� �ߺ� ���ڿ� ����!
#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);

	string str,temp;
	set<string> arr; // ������ �ߺ��� ������� �ʴ´�.
	cin >> str;
	int size = str.length();

	for (int i = 0; i < str.length(); i++) {
		for (int j = size; j > 0; j--) {
			// �ε��� i���� j��ŭ�� ���̸� �߶󳽴�
			// ex) 0,1�̸� 0��° �ε������� 1��ŭ �߶󳻴� �Ŵϱ� 0��° �ε��� ���� ������ �ȴ�!
			temp = str.substr(i, j);
			arr.insert(temp);
		}
		size--;
	}

	cout << arr.size();
	return 0;
}