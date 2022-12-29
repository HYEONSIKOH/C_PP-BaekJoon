#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int M, N; cin >> M >> N;
	int s_M = sqrt(M);
	int s_N = sqrt(N);
	int sum = 0;

	if (s_M * s_M != M) s_M++;
	int min = s_M * s_M;
	for (int i = s_M; i <= s_N; i++) sum += i * i;
	
	if (sum == 0) cout << -1;
	else cout << sum << '\n' << min;

	return 0;
}
