// 백준 24060 [병합 정렬] 알고리즘 병합정렬 복습
#include <stdio.h>
#include <stdlib.h>

int* arr;
int size,cnt = 0,ord;
int Bool = 0;

// =================== 병합 함수 ===================
void merge(int start, int mid, int end) {
	int s = start;
	int m = mid + 1;
	int idx = 0;
	int* temp = (int*)malloc(sizeof(int) * (end - start + 1));

	while (s <= mid && m <= end) {
		if (arr[s] < arr[m]) temp[idx++] = arr[s++];
		else temp[idx++] = arr[m++];

		cnt++;
		if (cnt == ord) {
			printf("%d", temp[idx - 1]);
			Bool = 1;
			return;
		}
	}

	while (s <= mid) {
		temp[idx++] = arr[s++];
		cnt++;

		if (cnt == ord) {
			printf("%d", temp[idx - 1]);
			Bool = 1;
			return;
		}
	}
	while (m <= end) {
		temp[idx++] = arr[m++];
		cnt++;

		if (cnt == ord) {
			printf("%d", temp[idx - 1]);
			Bool = 1;
			return;
		}
	}

	int idx2 = 0;
	int s2 = start;

	while (s2 <= end) arr[s2++] = temp[idx2++];
	free(temp);
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
	scanf("%d %d", &size, &ord);
	arr = (int*)malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++) scanf("%d", &arr[i]);

	merge_sort(0, size - 1);

	if(Bool == 0) printf("%d", -1);

	return 0;
}