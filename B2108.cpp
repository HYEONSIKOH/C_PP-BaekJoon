//백준 2108 산술평균, 중앙값, 최빈값, 범위
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int flag;
	int cnt[8002];

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num;
	cin >> num;
	vector<int> arr;
	int n;

	for (int i = 0; i < 8002; i++) cnt[i] = 0;

	for (int i = 0; i < num; i++) {
		cin >> n;
		arr.push_back(n);
		cnt[n + 4000]++;
	}
	sort(arr.begin(), arr.end());
	
	int min, max;
	min = arr[0];
	max = arr[0];

	// 산술평균
	double ave = 0;
	for (auto& e : arr) ave += e;
	ave = round(ave / num);

	if (ave == -0) ave = 0;

	cout << ave << "\n"; // round는 반올림할때 사용하는 키워드

	// 중앙값
	if (num % 2 != 0) cout << arr[num / 2] << "\n"; // num이 홀수
	else cout << (arr[num / 2] + arr[num / 2 + 1]) / 2 << "\n"; // num이 짝수

	// 최빈값
	int max_ = 0;

	for (int i = 0; i < 8002; i++){
		if (cnt[i] > max_){
			max_ = cnt[i];
			flag = i;
		}
	}

	for (int i = flag + 1; i < 8002; i++){
		if (cnt[i] == max_){
			flag = i;
			break;
		}
	}
	
	cout << flag-4000 << "\n";

	// 범위
	for (int i = 0; i < num; i++) {
		if (arr[i] < min) min = arr[i];
		if (arr[i] > max) max = arr[i];
	}
	
	cout << max - min << "\n";

	return 0;
}