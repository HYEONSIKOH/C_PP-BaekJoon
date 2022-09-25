// 백준 11497 [그리디 알고리즘] 난이도가 가장 낮은 통나무 건너뛰기 
#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int num,n,size;
	cin >> num;
	priority_queue <int , vector<int>, greater<int >> q; // 오름차순 우선순위 큐
	
	for (int index = 0; index < num; index++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> size;
			q.push(size);
		}
		
		vector<int> v(n);
		int front = 0, end = n - 1;
		
		// n값이 7이면 0 6 1 5 2 4 3 이런 순으로 맨 앞이랑 맨 뒤랑 번갈아가면서 넣는다.
		while (front < end) {
			v[front++] = q.top();
			q.pop();
			v[end--] = q.top();
			q.pop();
		}
		if (front == end) {
			v[front] = q.top();
			q.pop();
		}

		// 통나무 길이의 차의 최댓값 찾는 문장
		int max = 0,k = 0;
		for (int i = 0; i < n; i++) {
			if (i != n-1) k = abs(v[i] - v[i + 1]);
			else k = abs(v[0] - v[n-1]);
			
			if (max < k) max = k;
		}

		cout << max << '\n';
		v.clear();
	}
}