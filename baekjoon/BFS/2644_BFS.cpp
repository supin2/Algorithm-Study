#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 101;
int N, Start, End, relations;
int family[MAX][MAX];
int visited[MAX];

queue<int> q;

void BFS() {
    visited[Start] = 1;
    q.push(Start);

    while(!q.empty()) {
        int now = q.front();
        q.pop();

        if (now == End) {
            return;
        }
        for (int i = 1; i <= N; ++i) {
            if (family[now][i] == 1 && visited[i] == 0) { // 연관이 있고, 아직 계산안한 사람
                visited[i] = visited[now] + 1;
                q.push(i);
            }
        }
    }
}

int main() {
    
    cin >> N;
    cin >> Start >> End;
    cin >> relations;

    memset(family, 0, sizeof(family));

    for (int i = 0; i < relations; i++) {
        int parent, child;
        cin >> parent >> child;

        family[parent][child] = 1;
        family[child][parent] = 1;
    }
    BFS();
    
    int ans = visited[End] == 0 ? -1 : visited[End] - 1;
    cout << ans << '\n';

    return 0;
}