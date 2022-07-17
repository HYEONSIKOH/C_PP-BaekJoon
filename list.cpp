#include <iostream>
#include <time.h>
#include <list>
using namespace std;

int main() {
	list<int> values;

	// auto는 자바스크립트 처럼 변수 형식을 지정해주지 않고, 데이터 값에 맞는 형식으로 자동 변환된다.
	auto p = "k";
	auto num = 3;
	auto dou = 4.2;

	srand(time(NULL));

	for (int i = 0; i < 100; i++) values.push_back(rand() % 100); // 컨테이너 끝에 난수 추가

	values.sort();

	// 범위 기반의 루프 사용
	// 예전에는 반복자의 정확한 자료형을 알아야 했지만, auto 키워드가 그걸 대신해주고 있다.
	for (auto& e : values) cout << e << " ";

	cout << "\n" << size(values); // 사이즈를 나타내는 키워드

	return 0;

	// 610쪽 덱 공부할 차례
}