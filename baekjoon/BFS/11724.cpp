// 백준 11724번 : 연결 요소의 개수
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int N, M;
vector<int> V[1001];
bool visited[1001];

void BFS(int v) {
    queue<int> q;
    q.push(v);
    visited[v] = true;

    while(!q.empty()) {
        int now = q.front();
        q.pop();

        for (int i = 0; i < V[now].size(); ++i) {
            if (!visited[V[now][i]]) {
                visited[V[now][i]] = true;
                q.push(V[now][i]);
            }
        }
    }
}


int main() {
    cin >> N >> M;
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < M; ++i) {
        int v1, v2;
        cin >> v1 >> v2;

        V[v1].push_back(v2);
        V[v2].push_back(v1);
    }

    int cnt = 0;
    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            cnt++;
            BFS(i);
        }
    }

    cout << cnt << '\n';
    return 0;
}