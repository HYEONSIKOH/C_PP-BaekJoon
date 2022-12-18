// ���� 9344 [ũ����Į] ����
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, p, q, num;
bool b = false;

typedef struct Node {
    int a; // ���� ����
    int b; // ���� ����
}Node;

bool compare(pair<int, Node> a, pair<int, Node> b) {
    return a.first < b.first;
}

vector<pair<int, Node>> v;
vector<int> parent; // �θ�

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
        if ((e.a == p && e.b == q) || (e.a == q && e.b == p)) b = true;
    }
}

void init() {
    parent.resize(N + 1);
    for (int i = 1; i <= N; i++) parent[i] = i; // �θ� �� �ʱ�ȭ
    v.clear();
    b = false;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> num;
    while (num--) {
        cin >> N >> M >> p >> q;
        init();

        Node n;
        int cost;
        for (int i = 1; i <= M; i++) {
            cin >> n.a >> n.b >> cost;
            v.push_back({ cost,n });
        }

        sort(v.begin(), v.end(), compare); // �������� ����

        for (int i = 0; i < v.size(); i++) kruskal(v[i].second);

        bool ans = true;
        for (int i = 2; i <= N; i++) if (parent[i] == i) ans = false;

        if (ans && b) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
