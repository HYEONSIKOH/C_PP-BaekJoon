// ���� 21924 [ũ����Į] �ּ� ���� Ʈ�� ���� ��, �������� ��� ����ϱ�!
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

typedef struct Node {
    long long a; // ���� ����
    long long b; // ���� ����
    long long c; // ���
}Node;

struct comp {
    bool operator()(Node& a, Node& b) {
        return a.c > b.c;
    }
};

priority_queue<Node, vector<Node>, comp > pq; // �ּ���
vector<long long> parent; // �θ�
long long ans = 0;
int cnt = 0;

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

void kruskal(Node e) {
    if (!find(e.a, e.b)) {
        Union(e.a, e.b);
        cnt++;
    }

    else ans += e.c;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Node n;
    long long N, M;
    cin >> N >> M;

    parent.resize(N + 1);

    for (int i = 1; i <= N; i++) parent[i] = i;

    for (int i = 0; i < M; i++) {
        cin >> n.a >> n.b >> n.c;
        pq.push(n);
    }

    while (!pq.empty()) {
        kruskal(pq.top());
        pq.pop();
    }

    if (cnt != N - 1) cout << -1;
    else cout << ans;

    return 0;
}
