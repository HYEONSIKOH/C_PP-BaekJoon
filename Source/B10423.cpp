// 백준 10423 [프림] 시작지점이 k개인 프림 알고리즘
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq; // 최소힙

vector<bool> Find;
vector< vector<pair<int, int>> > vec;
vector<int> Electric_Power_Station;
int ans = 0, N, M, k;

void prim(int s) {
    Find[s] = true;

    for (auto& e : vec[s]) if (!Find[e.first]) pq.push({ e.second,e.first });

    while (!pq.empty()) {
        pair<int, int> p = pq.top();
        pq.pop();

        if (!Find[p.second]) {
            ans += p.first;
            prim(p.second);
            return;
        }
    }
}

void prim_start() {
    for (int i = 0; i < k; i++) {
        int s = Electric_Power_Station[i];
        Find[s] = true;

        for (auto& e : vec[s]) if (!Find[e.first]) pq.push({ e.second,e.first });
    }

    while (!pq.empty()) {
        pair<int, int> p = pq.top();
        pq.pop();

        if (!Find[p.second]) {
            ans += p.first;
            prim(p.second);
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> k;
    vec.resize(N + 1);
    Find.resize(N + 1);
    Electric_Power_Station.resize(k);

    for (int i = 0; i < k; i++) cin >> Electric_Power_Station[i];

    int a, b, c;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;

        vec[a].push_back({ b,c });
        vec[b].push_back({ a,c });
    }
    prim_start();

    cout << ans;
    return 0;
}