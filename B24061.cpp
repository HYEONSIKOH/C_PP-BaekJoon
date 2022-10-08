// 백준 24061 [병합 정렬] 알고리즘 병합정렬 복습 2
#include <iostream>
#include <vector>
using namespace std;

int* arr;
int sz, cnt = 0, ord;
int Bool = 0;

// =================== 병합 함수 ===================
void merge(int start, int mid, int end) {
	int s = start;
	int m = mid + 1;
	int idx = 0;
	int n = 0;
	vector<int> temp(end - start + 1);

	while (s <= mid && m <= end) {
		if (arr[s] < arr[m]) temp[idx++] = arr[s++];
		else temp[idx++] = arr[m++];

		cnt++;
		
		if (cnt == ord) {
			for (int i = 0; i < sz; i++) {
				if (start <= i && i <= start + (idx - 1)) cout << temp[n++] << ' ';
				else cout << arr[i] << ' ';
			}
			Bool = 1;
			return;
		}
	}

	while (s <= mid) {
		temp[idx++] = arr[s++];
		cnt++;

		if (cnt == ord) {
			for (int i = 0; i < sz; i++) {
				if (start <= i && i <= start + (idx - 1)) cout << temp[n++] << ' ';
				else cout << arr[i] << ' ';
			}
			Bool = 1;
			return;
		}
	}

	while (m <= end) {
		temp[idx++] = arr[m++];
		cnt++;

		if (cnt == ord) {
			for (int i = 0; i < sz; i++) {
				if (start <= i && i <= start + (idx - 1)) cout << temp[n++] << ' ';
				else cout << arr[i] << ' ';
			}
			Bool = 1;
			return;
		}
	}

	int idx2 = 0;
	int s2 = start;

	while (s2 <= end) arr[s2++] = temp[idx2++];
	temp.clear();
}

void merge_sort(int start, int end) {
	int mid;

	if (start < end) {
		mid = (start + end) / 2;
		merge_sort(start, mid);
		merge_sort(mid + 1, end);
		merge(start, mid, end);
	}
}

int main() {
	ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

	cin >> sz >> ord;
	arr = new int[sz];
	for (int i = 0; i < sz; i++) cin >> arr[i];

	merge_sort(0, sz - 1);

	if (Bool == 0) cout << -1;

	delete[] arr;
	return 0;
}