// 백준 11279 우선순위 큐 변수 선언 및 pop(), push() 명령어 사용
#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);

	int num;
	cin >> num;

	priority_queue<int> q; // 내림차순 우선순위 큐

	int n = 0;

	for (int i = 0; i < num; i++) {
		cin >> n;
		if (n == 0) {
			if (q.empty()) cout << 0 << '\n';
			
			else {
				cout << q.top() << '\n';
				q.pop();
			}
		}
		else q.push(n);
	}

	return 0;
}