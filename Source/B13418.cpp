// 백준 13418 [크루즈칼] 국민대학교 언덕 이용 횟수 구하기....;
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct Node {
    int a; // 시작 정점
    int b; // 도착 정점
}Node;

bool compare(pair<int, Node> a, pair<int, Node> b) {
    return a.first > b.first;
}

vector<pair<int, Node>> v;

vector<int> parent; // 부모
int cnt = 0;
int Min, Max;

int getRoot(int x) {
    if (parent[x] == x) return x;
    return parent[x] = getRoot(parent[x]);
}

void Union(int a, int b) {
    a = getRoot(a);
    b = getRoot(b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

bool find(int a, int b) {
    a = getRoot(a);
    b = getRoot(b);
    if (a == b) return true;
    else return false;
}

void kruskal(Node e,int c) {
    if (!find(e.a, e.b)) {
        Union(e.a, e.b);
        if (c == 0) cnt++;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Node n;
    int N, M; // N은 정점, M은 간선 개수
    cin >> N >> M;
    parent.resize(N+1, 0);

    for (int i = 1; i <= N; i++) parent[i] = i;

    int cost;
    for (int i = 0; i <= M; i++) {
        cin >> n.a >> n.b >> cost;
        v.push_back({ cost,n });
    }

    sort(v.begin(), v.end(), compare); // 내림차순 정렬

    for (int i = 0; i < v.size(); i++) kruskal(v[i].second, v[i].first);
    Min = cnt;
    cnt = 0;

    for (int i = 1; i <= N; i++) parent[i] = i; // 부모 값 초기화

    for(int i = v.size() - 1; i>=0; i--) kruskal(v[i].second, v[i].first);
    Max = cnt;

    cout << abs(Max * Max - Min * Min);

    return 0;
}
