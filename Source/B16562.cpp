// 백준 16562 [분할집합] 친구비
#include <iostream>
#include <vector>
#define INF 123456789
using namespace std;

long long n, m, k;
vector<long long> parent;
vector<long long> cost;
vector<long long> vec;

// 루트 노드 찾기
long long find(long long x) {
	if (x == parent[x]) return x; // 같으면 루트노드

	parent[x] = find(parent[x]); // 재귀로 부모노드 접근
	return parent[x];
}

// 합치기
void Union(long long x, long long y) {
	// 각 부모노드를 비교
	x = find(x);
	y = find(y);

	if (x == y) return; // 이미 같은 집합
	else if (x < y) parent[y] = x; // 합한다
  else parent[x] = y;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	cin >> n >> m >> k;
	parent.resize(n + 1);
  cost.resize(n + 1);

  int max = 0;
	// 초기화
	for (int i = 1; i <= n; i++){
    parent[i] = i;
    cin >> cost[i];

    if(i == 1) max = cost[i];
    else 
      if(max < cost[i]) max = cost[i];
    
  } 

  vec.resize(n + 1 ,max+1);

	for (int i = 0; i < m; i++) {
		long long a, b;
		cin >> a >> b;
    Union (a,b);
	}

  for (int i = 1; i <= n; i++)
		if(vec[find(i)] > cost[i]) vec[find(i)] = cost[i];
  
  long long sum = 0;
  
  for(int i = 1; i<= n; i++) if(vec[i] <= max) sum += vec[i];

  if(sum <= k) cout << sum;
  else cout << "Oh no";
  
	return 0;
}
