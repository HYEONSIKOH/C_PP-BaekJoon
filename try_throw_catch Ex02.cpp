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
		cout << "피자 조각 수를 입력하세요: ";
		cin >> pizza_slices;
		cout << "사람 수를 입력하시오: ";
		cin >> persons;

		slice_per_person = dividePizza(pizza_slices, persons);

		cout << "한사람당 피자는 " << slice_per_person << "입니다." << "\n";
	}
	catch (int e) { // 오류를 물론 한개만 할 수도 있지만,
		cout << "[오류] 사람이 " << e << " 명 입니다. " << "\n";
	}
	catch (const char* e) { // 오류를 두개 이상으로도 잡을 수 있다.
		cout << "[오류] 사람수가 " << e << " 입니다. " << "\n";
	}

	return 0;
}