// 백준 16202 [프림] 최소신장트리 게임!
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

priority_queue <pair<int, int> , vector<pair<int,int>>, greater<pair<int,int>> > pq;
vector<bool> visit;
vector<bool> v;
vector< vector<pair<int, int>> > vec;
int N, M, K;
int ans = 0, cnt = 0;

void prim(int s) {
    visit[s] = true;

    for (auto& e : vec[s]) if (!visit[e.first] && !v[e.second]) pq.push({ e.second,e.first });

    while (!pq.empty()) {
        pair<int, int> p = pq.top(); // first = 비용, second = 도착정점
        pq.pop();

        if (!visit[p.second]) {
            ans += p.first;
            prim(p.second);
            return;
        }
    }
}

void init() {
    for (int i = 0; i <= N; i++) visit[i] = false;
    ans = 0;
    v[++cnt] = true;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M >> K;

    vec.resize(N + 1);
    visit.resize(N + 1,false);
    v.resize(M + 1, false);

    int a, b;
    int start;
    for (int i = 1; i <= M; i++) {
        cin >> a >> b;
        vec[a].push_back({ b,i });
        vec[b].push_back({ a,i });
    }

    for (int i = 0; i < K; i++) {
        prim(a);

        bool TF = true;
        for (int j = 1; j <= N; j++) {
            if (!visit[j]) {
                TF = false;
                break;
            }
        }

        if (TF) cout << ans << ' ';
        else cout << "0 ";
        init();
    }

    return 0;
}
