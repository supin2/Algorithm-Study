// 백준 11725번 : 트리의 부모 찾기
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 100000 + 1;
int N;
vector<int> vec[MAX];
int parent[MAX] = { 0, };

void BFS() {
    queue<int> q;
    q.push(1);
    parent[1] = 1;

    while(!q.empty()) {
        int now = q.front();
        q.pop();

        for (auto& next : vec[now]) {
            cout << next << '\n';
            if (parent[now] == next) continue;
            parent[next] = now;
            q.push(next);
        }
    }
}


int main() {
    cin >> N;
    
    for (int i = 0; i < N - 1; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        vec[v1].push_back(v2);
        vec[v2].push_back(v1);
    }
    BFS();

    for (int i = 2; i <= N; ++i) {
        cout << parent[i] << '\n';
    }
    return 0;
}