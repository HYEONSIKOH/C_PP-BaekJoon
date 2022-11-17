// 백준 1774 [크루즈칼] 하.... 행성 연결하다가 내가 염라대왕하고 연결 될 뻔했다.
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

typedef struct Node {
    long long a; // 시작 정점
    long long b; // 도착 정점
    long double c; // 비용
}Node;

typedef struct pos {
    long long x;
    long long y;
}pos;

struct comp {
    bool operator()(Node& a, Node& b) {
        return a.c > b.c;
    }
};

priority_queue<Node, vector<Node>, comp > pq; // 최소힙
vector<pos> v;
map<pair<long, long>, bool> m;
long long parent[1001]; // 부모
long double ans = 0;

long long getRoot(long long x) {
    if (parent[x] == x) return x;
    return parent[x] = getRoot(parent[x]);
}

void Union(long long a, long long b) {
    a = getRoot(a);
    b = getRoot(b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

bool find(long long a, long long b) {
    a = getRoot(a);
    b = getRoot(b);
    if (a == b) return true;
    else return false;
}

void kruskal(Node e) {
    if (!find(e.a, e.b)) {
        Union(e.a, e.b);
        ans += e.c;
    }
}

long double length(pos a, pos b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() {
    //ios_base::sync_with_stdio(0);cin.tie(0);

    Node n;
    int N, M;
    cin >> N >> M;
    v.resize(N + 1);
    long long K, k;

    for (int i = 1; i <= N; i++) cin >> v[i].x >> v[i].y;

    for (int i = 0; i < M; i++) {
        cin >> K >> k;
        m[{K, k}] = true;
    }

    for (int i = 1; i <= N; i++) parent[i] = i;

    for (int i = 1; i < N; i++) {
        for (int j = i + 1; j <= N; j++) {
            n.a = i;
            n.b = j;
            n.c = length(v[i], v[j]);

            if (m[{i, j}] || m[{j, i}]) {
                n.c = 0;
                kruskal(n);
            }
            else pq.push(n);
        }
    }

    while (!pq.empty()) {
        kruskal(pq.top());
        pq.pop();
    }

    printf("%.2Lf\n", ans);
    return 0;
}
