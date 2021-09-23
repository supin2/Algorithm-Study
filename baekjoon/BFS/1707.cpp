// 백준 1707번 : 이분 그래프
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 20000 + 1;
int K, V, E;
vector<int> vec[MAX];
int color[MAX];

bool isBipartite() {
    for (int i = 1; i <= V; ++i) {
        int cmp1 = color[i];
        for (int j = 0; j < vec[i].size(); ++j) {
            if (cmp1 == color[vec[i][j]]) {
                return false;
            }
        }
    }
    return true;
}


void BFS(int vt) {
    queue<int> q;
    q.push(vt);
    color[vt] = 1;

    while(!q.empty()) {
        int now = q.front();
        q.pop();

        for (auto& next : vec[now]) {
            if (color[next] == 0) {
                if (color[now] == 1) {
                    color[next] = 2;
                    q.push(next);
                } else if (color[now] == 2) {
                    color[next] = 1;
                    q.push(next);
                }
            }
        }
    }
}


int main() {
    cin >> K;

    while(K--) {
        cin >> V >> E;

        for (int i = 1; i <= V; ++i) {
            vec[i].clear();
            color[i] = 0;
        }

        for (int i = 0; i < E; ++i) {
            int v1, v2;
            cin >> v1 >> v2;
            vec[v1].push_back(v2);
            vec[v2].push_back(v1);
        }
        for (int i = 1; i <= V; ++i) {
            if (color[i] == 0) {
                BFS(i);
            }
        }

        if (isBipartite()) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}