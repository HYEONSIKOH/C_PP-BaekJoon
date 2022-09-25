// ���� 11497 [�׸��� �˰���] ���̵��� ���� ���� �볪�� �ǳʶٱ� 
#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int num,n,size;
	cin >> num;
	priority_queue <int , vector<int>, greater<int >> q; // �������� �켱���� ť
	
	for (int index = 0; index < num; index++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> size;
			q.push(size);
		}
		
		vector<int> v(n);
		int front = 0, end = n - 1;
		
		// n���� 7�̸� 0 6 1 5 2 4 3 �̷� ������ �� ���̶� �� �ڶ� �����ư��鼭 �ִ´�.
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

		// �볪�� ������ ���� �ִ� ã�� ����
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