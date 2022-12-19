// 백준 1414 [프림] 크리스마스 기념 불우이웃돕기!
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq; // 최소힙

vector<bool> Find;
vector< vector<pair<int, int>> > vec;
int ans = 0;
int num;

void prim(int s) {
    Find[s] = true;

    for (auto& e : vec[s]) if (!Find[e.first]) pq.push({ e.second,e.first });

    while (!pq.empty()) {
        pair<int, int> p = pq.top();
        pq.pop();

        if (!Find[p.second]) {
            ans -= p.first;
            prim(p.second);
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> num;

    vec.resize(num + 1);
    Find.resize(num + 1);

    char ch;
    int start, min = 987654321;
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            cin >> ch;
            
            if ('a' <= ch && ch <= 'z') {
                if (i != j) {
                    vec[i].push_back({ j, ch - 96 });
                    vec[j].push_back({ i, ch - 96 });
                }
                ans += ch - 96;

                if (min > ch - 96) {
                    min = ch - 96;
                    start = i;
                }
            }

            else if ('A' <= ch && ch <= 'Z') {
                if (i != j) {
                    vec[i].push_back({ j, ch - 38 });
                    vec[j].push_back({ i, ch - 38 });
                }
                ans += ch - 38;

                if (min > ch - 96) {
                    min = ch - 38;
                    start = i;
                }
            }
        }
    }

    prim(start);

    bool s = true;
    for (int i = 0; i < num; i++) if (!Find[i]) s = false;

    if (!s) cout << -1;
    else cout << ans;

    return 0;
}
