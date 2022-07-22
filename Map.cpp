#include <map>
#include <iostream>
using namespace std;

int main() {
	map<string, string> myMap; // ù��°�� Ű(key) Ÿ��, �ι�°�� ��(value) Ÿ��

	myMap.insert(make_pair("��ö��", "010-123-5678")); // Map�� �����͸� �����ϴ� ù��° ��� insert() ���.
	myMap.insert(make_pair("ȫ�浿", "010-123-5678"));

	myMap["���ڿ�"] = "010-123-5678"; // Map�� �����͸� �����ϴ� �ι�° ���, myMap[key��] = value�� ���.

	// ��� ��� ���
	for (auto& it : myMap) cout << it.first << " :: " << it.second << endl;

	// find()�� ����ϸ�, Map���� �� ���� ã�Ƴ� �� �ִ�. end()���� ���ٴ� ����, �� ���� ���ٴ� ���̴�.
	// �Ƹ� ���ڿ� Ž��ó�� ������(�ּ�)���� ��ȯ�ϴ� ����̴�.
	if (myMap.find("�迵��") == myMap.end())
		cout << "�ܾ� '�迵��'�� �߰ߵ��� �ʾҽ��ϴ�.\n";

	return 0;
}