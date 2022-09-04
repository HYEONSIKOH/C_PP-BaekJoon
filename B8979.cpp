// 백준 8979 올림픽 순위를 매겨보자!
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(vector<int> a, vector<int> b) {
	if (a[1] > b[1]) // 금으로 비교가 될 때
		return true;

	else if (a[1] == b[1]) { // 금의 개수가 똑같은 경우
		if (a[2] > b[2]) return true;

		else if (a[2] == b[2]) { // 은의 개수도 똑같은 경우
			if (a[3] > b[3]) return true;
			else return false;
		}

		else return false;
	}

	else return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N, K;
	cin >> N >> K;
	vector<vector<int>> con;

	for (int i = 0; i < N; i++) {
		vector<int> arr(5);
		cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
		con.push_back(arr);
	}

	sort(con.begin(), con.end(), compare);

	int index;
	
	con[0][4] = 1;
	for (int i = 1; i < N; i++) {
		if ((con[i][1] == con[i - 1][1]) 
			&& (con[i][2] == con[i - 1][2]) 
			&& (con[i][3] == con[i - 1][3]))
			con[i][4] = con[i - 1][4];
		else
			con[i][4] = i + 1;

		if (con[i][0] == K) index = i;
	}

	if (con[0][0] == K) index = 0;
	cout << con[index][4];

	return 0;
}
