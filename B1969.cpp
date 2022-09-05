// 백준 1969 [그리디 알고리즘] DNA 염기서열 Hamming Distance 최솟값 구하기!
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<string> dna;
	string temp;
	vector<pair<char, int>> arr(4);
	arr = { {'A',0},{'C',0} ,{'G',0},{'T',0} };

	for (int i = 0; i < N; i++) {
		cin >> temp;
		dna.push_back(temp);
	}

	int max_index, max = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (dna[j][i] == 'A') arr[0].second++;
			else if (dna[j][i] == 'C') arr[1].second++;
			else if (dna[j][i] == 'G') arr[2].second++;
			else if (dna[j][i] == 'T') arr[3].second++;
		}

		for (int k = 0; k < 4; k++) {
			if (max < arr[k].second) {
				max_index = k;
				max = arr[k].second;
			}
			arr[k].second = 0;
		}

		temp[i] = arr[max_index].first;
		max = 0;
	}
	int count = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (dna[j][i] != temp[i]) count++;
		}
	}

	cout << temp << '\n' << count;

	return 0;
}