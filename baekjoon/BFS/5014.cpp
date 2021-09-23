#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 1000001;

int F, S, G, U, D, ans;
int dist[MAX];
queue<int> q;

int BFS(int Start, int Goal) {
    q.push(Start);
    dist[Start] = 1;

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        if (now == Goal) {
            return dist[Goal] - 1;
        }

        int nextFloor[2] = { now + U, now - D };
        for (int i = 0; i < 2; ++i) {
            if (1 <= nextFloor[i] && nextFloor[i] <= F && dist[nextFloor[i]] == 0) {
                dist[nextFloor[i]] = dist[now] + 1;
                q.push(nextFloor[i]);
            }            
        }
    }
    return -1;
}


int main() {
    cin >> F >> S >> G >> U >> D;

    memset(dist, 0, sizeof(dist));

    ans = BFS(S, G);

    if (ans == -1) {
        cout << "use the stairs" << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}