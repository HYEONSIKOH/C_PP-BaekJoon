// 백준 14950 [프림] 정복자
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq; // 최소힙

vector<bool> Find;
vector< vector<pair<int, int>> > vec;
int ans = 0, cnt = 0, N, M, t;

void prim(int s) {
    Find[s] = true;

    for (auto& e : vec[s]) if (!Find[e.first]) pq.push({ e.second,e.first });

    while (!pq.empty()) {
        pair<int, int> p = pq.top();
        pq.pop();

        if (!Find[p.second]) {
            ans += p.first + (cnt++ * t);
            prim(p.second);
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  
    cin >> N >> M >> t;
    vec.resize(N+1);
    Find.resize(N+1);

    int a,b,c;
    for(int i = 0; i<M; i++){
        cin >> a >> b >> c;
        
        vec[a].push_back({b,c});
        vec[b].push_back({a,c});
    }
    prim(1);

    cout << ans;
    return 0;
}
