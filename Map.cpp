#include <map>
#include <iostream>
using namespace std;

int main() {
	map<string, string> myMap; // 첫번째는 키(key) 타입, 두번째는 값(value) 타입

	myMap.insert(make_pair("김철수", "010-123-5678")); // Map에 데이터를 저장하는 첫번째 방법 insert() 사용.
	myMap.insert(make_pair("홍길동", "010-123-5678"));

	myMap["최자영"] = "010-123-5678"; // Map에 데이터를 저장하는 두번째 방법, myMap[key값] = value값 사용.

	// 모든 요소 출력
	for (auto& it : myMap) cout << it.first << " :: " << it.second << endl;

	// find()를 사용하면, Map에서 그 값을 찾아낼 수 있다. end()까지 갔다는 것은, 그 값이 없다는 뜻이다.
	// 아마 문자열 탐색처럼 포인터(주소)값을 반환하는 모양이다.
	if (myMap.find("김영희") == myMap.end())
		cout << "단어 '김영희'는 발견되지 않았습니다.\n";

	return 0;
}