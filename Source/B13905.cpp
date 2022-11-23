// 백준 13905 [프림] 황금빼빼로를 왜 자꾸 옮기냐....;
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

priority_queue <pair<int,int>> pq;
vector<bool> visit;
vector< vector<pair<int, int>> > vec;
int N, M, S, E;
int ans = 1000000;

void prim(int s, int e) {
    visit[s] = true;
    if (s == e) return;

    for (auto& e : vec[s]) if (!visit[e.first]) pq.push({ e.second,e.first });

    while (!pq.empty()) {
        pair<int,int> p = pq.top();
        pq.pop();

        if (!visit[p.second]) {
            if(ans > p.first) ans = p.first;
            prim(p.second, e);
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M >> S >> E;
    visit.resize(N + 1, false);
    vec.resize(N + 1);

    int a, b, cost;
    for (int i = 1; i <= M; i++) {
        cin >> a >> b >> cost;
        vec[a].push_back({ b,cost });
        vec[b].push_back({ a,cost });
    }

    prim(S, E);

    if (visit[E]) cout << ans;
    else cout << 0;

    return 0;
}