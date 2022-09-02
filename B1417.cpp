// 백준 1417 [그리디 알고리즘] 부정한 방법으로 국회의원이 되자!
#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	priority_queue<int> q; // 내림차순 우선순위 큐

	int num;
	cin >> num;

	int first, n, count = 0;
	for (int i = 0; i < num; i++) {
		if (i == 0) cin >> first; // 기호 1번은 큐에서 제외
		else {
			cin >> n;
			q.push(n);
		}
	}
	if (num == 1) {
		cout << 0;
		return 0;
	}
	while (1) {
		if (q.top() < first) break;
		else {
			n = q.top(); // 가장 높은 투표 수
			q.pop();
			n--; // 가장 높은 투표 수의 사람을 투표 한 사람 중 한명을,
			first++; // 뒷돈주고 포섭하면
			count++; // 내 투표수가 1 증가하고 가장 높은 놈은 1 떨어진다.
			q.push(n);
		}
	}

	cout << count;
	return 0;
}