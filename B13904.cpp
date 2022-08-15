// 백준 13904 효율적으로 과제 점수 획득하기
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);

	vector <pair<int, int>> arr;
	priority_queue<int,vector<int>,greater<int>> q;
	int num;
	cin >> num;

	// 일단 백터에 저장한 뒤, 마감일 순으로 오름차순 정렬!
	int day,grade;
	for (int i = 0; i < num; i++) {
		cin >> day >> grade;
		arr.push_back(make_pair(day, grade));
	}
	sort(arr.begin(), arr.end());
	
	// 오름차순(최소힙) 우선순위 큐에 집어 넣으면서,
	for (int i = 0; i < num; i++) {
		day = arr[i].first;
		grade = arr[i].second;

		q.push(grade);

		// size는 과제를 한 것의 총 개수, 내 일수보다 과제 수가 더 많으면 안된다
		// 과제는 하루에 한개씩만 할 수 있다.
		// 최솟값 아무거나 pop을 해도 되는 이유는, 어짜피 마감일 순으로 오름차순 했기 때문에!
		if (q.size() > day) q.pop();
	}

	int sum_grade = 0;
	while (!q.empty()) {
		sum_grade += q.top();
		q.pop();
	}

	cout << sum_grade;
	return 0;
}