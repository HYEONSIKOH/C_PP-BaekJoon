#include <iostream>
#include <time.h>
#include <list>
using namespace std;

int main() {
	list<int> values;

	// auto�� �ڹٽ�ũ��Ʈ ó�� ���� ������ ���������� �ʰ�, ������ ���� �´� �������� �ڵ� ��ȯ�ȴ�.
	auto p = "k";
	auto num = 3;
	auto dou = 4.2;

	srand(time(NULL));

	for (int i = 0; i < 100; i++) values.push_back(rand() % 100); // �����̳� ���� ���� �߰�

	values.sort();

	// ���� ����� ���� ���
	// �������� �ݺ����� ��Ȯ�� �ڷ����� �˾ƾ� ������, auto Ű���尡 �װ� ������ְ� �ִ�.
	for (auto& e : values) cout << e << " ";

	cout << "\n" << size(values); // ����� ��Ÿ���� Ű����

	return 0;

	// 610�� �� ������ ����
}