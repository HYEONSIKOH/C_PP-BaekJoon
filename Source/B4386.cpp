// 백준 4386 [프림] 별자리 만들기!
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
#define INF 987654321

vector<bool> visit;
vector<double> dist;
vector< vector<pair<int, double>> > vec;
vector<pair<double, double>> cur;
int N;

int get_min_v() {
    int v;
    for (int i = 1; i <= N; i++) {
        if (!visit[i]) {
            v = i; // 기준 점
            break;
        }
    }

    for (int i = 1; i <= N; i++)
        if (!visit[i] && (dist[i] < dist[v])) v = i; // 거리가 작은 정점 찾기!

    return v;
}

void prim() {
    for (int i = 1; i <= N; i++) {
        dist[i] = INF;
        visit[i] = false;
    }

    int u;
    dist[1] = 0;

    for (int i = 1; i <= N; i++) {
        u = get_min_v();
        visit[u] = true;

        if (dist[u] == INF) return;

        // DFS 탐색
        for (int v = 0; v < vec[u].size(); v++) {
            int cur = vec[u][v].first;
            if (!visit[cur] && vec[u][v].second < dist[cur]) {
                dist[cur] = vec[u][v].second;
            }
        }
    }
}

double length(pair<double,double> a, pair<double,double> b) {
    double x = (a.first - b.first), y = (a.second - b.second);
    double ans = sqrt(x * x + y * y);

    return ans;
}


int main() {
    cin >> N;
    dist.resize(N + 1, 987654321);
    visit.resize(N + 1, false);
    vec.resize(N + 1);
    cur.resize(N + 1);
    
    double a, b;
    for (int i = 1; i <= N; i++) {
        cin >> a >> b;
        cur[i] = { a,b };
    }
    
    for (int i = 1; i < N; i++) {
        for (int j = i + 1; j <= N; j++) {
            vec[i].push_back( { j,length(cur[i],cur[j]) } );
            vec[j].push_back({ i,length(cur[i],cur[j]) });
        }
    }

    prim();

    double ans = 0;
    for (int i = 1; i <= N; i++) ans += dist[i];

    cout << round(ans * 100) / 100 ;

    return 0;
}