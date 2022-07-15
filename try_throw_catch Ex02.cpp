#include <iostream>
using namespace std;

int dividePizza(int pizza_slices, int persons) {
	if (persons == 0) throw persons;
	else if (persons < 0) throw "negative";
	else return pizza_slices / persons;
}

int main() {
	int pizza_slices = 0;
	int persons = -1;
	int slice_per_person = 0;

	try {
		cout << "���� ���� ���� �Է��ϼ���: ";
		cin >> pizza_slices;
		cout << "��� ���� �Է��Ͻÿ�: ";
		cin >> persons;

		slice_per_person = dividePizza(pizza_slices, persons);

		cout << "�ѻ���� ���ڴ� " << slice_per_person << "�Դϴ�." << "\n";
	}
	catch (int e) { // ������ ���� �Ѱ��� �� ���� ������,
		cout << "[����] ����� " << e << " �� �Դϴ�. " << "\n";
	}
	catch (const char* e) { // ������ �ΰ� �̻����ε� ���� �� �ִ�.
		cout << "[����] ������� " << e << " �Դϴ�. " << "\n";
	}

	return 0;
}