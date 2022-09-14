// 백준 1246 [그리디 알고리즘] 사기꾼 달걀장수가 최대한 돈을 많이 벌어야 된다.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> Egg(M);
	for (int i = 0; i < M; i++) cin >> Egg[i];
	sort(Egg.begin(), Egg.end()); // 달걀가격 오름차순 정렬

	int Max_Index = 0, Money = 0;

	for (int i = 0; i < M; i++) {
		if ((M - i) > N) { // 주인장이 가지고 있는 달걀의 갯수가 손님의 수보다 적을 때
			if ((N * Egg[i]) > Money) {
				Money = N * Egg[i];
				Max_Index = i;
			}
		}
		else { // 주인장이 가지고 있는 달걀의 갯수가 손님의 수랑 같거나 더 많을 때!
			if (((M - i) * Egg[i]) > Money) {
				Money = (M - i) * Egg[i];
				Max_Index = i;
			}
		}
	}

	cout << Egg[Max_Index] << " " << Money;
	return 0;
}