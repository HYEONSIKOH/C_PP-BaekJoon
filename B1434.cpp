#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> boxs(N), books(M);

	for (int i = 0; i < N; i++) cin >> boxs[i];
	
	for (int i = 0; i < M; i++) cin >> books[i];

	for (int i = 0; i < M; i++){
		for (int j = 0; j < N; j++){
			if (boxs[j] >= books[i]){
				boxs[j] -= books[i];
				break;
			}
		}
	}

	cout << accumulate(boxs.begin(), boxs.end(), 0);
    return 0;
}
