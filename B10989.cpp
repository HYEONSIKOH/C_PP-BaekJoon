// 백준 10989 카운팅 정렬 문제

#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num;
	cin >> num;

	int arr;
	int max = 0;

	int* count_arr = new int[10001];

	for (int i = 0; i < 10001; i++) count_arr[i] = 0;

	for (int i = 0; i < num; i++) {
		cin >> arr;
		if (max < arr) max = arr;

		count_arr[arr]++;
	}

	int index = 0;
	int k = 0;

	while (1) {
		if (count_arr[index] != 0) {
			cout << index << "\n";
			count_arr[index]--;
			k++;
		}
		else
			index++;

		if (index > max)
			break;
	}

	delete[] count_arr;
	return 0;
}
