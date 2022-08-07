// ���� 11286 [�켱���� ť] pair�� �̿��� ���� ���ڸ� �ΰ��� ������ ��, ���� (make_pair)
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

	// pair�� ������� ù��° ���ڷ� �Ǵ��ϴµ�, ���� ù��° ���ڰ� ������ �ι�° ���ڷ� �Ǵ��Ѵ�.
	priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>> > q; // �������� �켱���� ť
	
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
		// ������ vector�� ���������� ���ڰ� �ΰ� �̻��� ��,
		// �Է��� make_pair(a,b)
		// ����� .first , .second 
		else q.push(make_pair(abs(n),n));
	}

	return 0;
}