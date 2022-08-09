// 백준 2075 [우선순위 큐] N번째로 큰 수 찾기!
#include <queue>
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num,n;
	cin >> num;

	priority_queue <int , vector<int>, greater<int>> q;

	for (int i = 0; i < num * num; i++) {
		cin >> n;
		q.push(n);
		if (q.size() > num) q.pop(); // 사이즈가 N보다 커지면 가장 작은 수를 버린다. (어짜피 그보다 작은 수들은 필요 없으니까!)
	}

	cout << q.top(); // 그러면 우선순위 큐의 루트노드의 값이 N번째로 큰수.

	return 0;
}