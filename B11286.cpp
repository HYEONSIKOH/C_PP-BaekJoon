// 백준 11286 [우선순위 큐] pair를 이용한 힙의 인자를 두개로 선언한 뒤, 사용법 (make_pair)
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);

	int num;
	cin >> num;

	// pair는 가장먼저 첫번째 인자로 판단하는데, 만약 첫번째 인자가 같으면 두번째 인자로 판단한다.
	priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>> > q; // 내림차순 우선순위 큐
	
	int n;
	for (int i = 0; i < num; i++) {
		cin >> n;

		if (n == 0) {
			if (q.empty()) cout << 0 << '\n';

			else {
				cout << q.top().second << '\n';
				q.pop();
			}
		}
		// 사용법은 vector과 마찬가지로 인자가 두개 이상일 때,
		// 입력은 make_pair(a,b)
		// 출력은 .first , .second 
		else q.push(make_pair(abs(n),n));
	}

	return 0;
}