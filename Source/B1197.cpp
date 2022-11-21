// 백준 1197 [최소 신장 트리] 상근이의 해외 여행!
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int T;
	cin >> T;

	for (int index = 0; index < T; index++) {
		int N, M;
		cin >> N >> M;

		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
		}

		cout << N - 1 << '\n';
	}

	return 0;
}