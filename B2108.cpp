//���� 2108 ������, �߾Ӱ�, �ֺ�, ����
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

	// ������
	double ave = 0;
	for (auto& e : arr) ave += e;
	ave = round(ave / num);

	if (ave == -0) ave = 0;

	cout << ave << "\n"; // round�� �ݿø��Ҷ� ����ϴ� Ű����

	// �߾Ӱ�
	if (num % 2 != 0) cout << arr[num / 2] << "\n"; // num�� Ȧ��
	else cout << (arr[num / 2] + arr[num / 2 + 1]) / 2 << "\n"; // num�� ¦��

	// �ֺ�
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

	// ����
	for (int i = 0; i < num; i++) {
		if (arr[i] < min) min = arr[i];
		if (arr[i] > max) max = arr[i];
	}
	
	cout << max - min << "\n";

	return 0;
}