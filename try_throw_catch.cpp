#include <iostream>
using namespace std;

int dividePizza(int pizza_slices, int persons) {
	if (persons == 0) throw persons;
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

		slice_per_person = dividePizza(pizza_slices, persons); // 함수를 통해서도 예외 처리가 가능!

		cout << "한사람당 피자는 " << slice_per_person << "입니다." << "\n";
	}
	catch (int e){
		cout << "사람이 " << e << " 명 입니다. " << "\n";
	}

	return 0;
}