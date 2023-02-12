// 백준 2725 [누적합] 보이는 점의 개수
#include<iostream>
using namespace std;

int gcd(int a, int b) {
	int t;
	while (b) {
		t = a % b;
		a = b;
		b = t;
	}
	return a;
}

int main() {
     ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int N;
	cin >> N;

    int psum[1001];
	psum[1] = 3;
	
    for (int i = 2; i <= 1000; i++) {
		int cnt = 0;
		
        for (int j = 1; j < i; j++) 
			if (gcd(i, j) == 1) cnt++;
		
		psum[i] = psum[i - 1] + 2 * cnt;
	}
	
    while (N--) {
		int n;
		
        cin >> n;
		cout << psum[n] << '\n';
	}
	
    return 0;
}
