// 백준 1655 [우선순위 큐] 힙을 두개 이용한 중앙값 찾기
// 로직은 이해했으나, 왜 이렇게 나오는지 궁금함......
// 뒤지게 어려운 문제중 한개
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int num,n;
	int temp_max, temp_min;
	cin >> num;

	priority_queue<int, vector<int>, greater<int>> min; // 작은 수들을 넣는 큐
	priority_queue<int> max; // 큰 수들을 넣는 큐

	// 최소 힙의 값들은 최대 힙의 값들보다 무조건 커야 됨!
	// 최대 힙의 크기는 최소 힙 크기보다 1크거나 같다. ==> 최대 힙에 값을 먼저 넣어야댐

	for (int i = 0; i < num; i++) {
		cin >> n;

		if (max.empty()) max.push(n);

		else {
			if (max.size() == min.size()) max.push(n);

			else min.push(n);

			if (max.top() > min.top()) {
				temp_max = max.top();
				temp_min = max.top();

				max.pop(), min.pop();

				max.push(temp_min);
				min.push(temp_max);
			}
		}

		cout << max.top() << '\n';
	}

	return 0;
}