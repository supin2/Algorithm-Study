// 백준 9466번 : 텀 프로젝트
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;


const int MAX = 100000 + 1;
int T, N, cnt;
int student[MAX];
bool visited[MAX];
bool finished[MAX];

void DFS(int v) {
    visited[v] = true;
    
    int next = student[v];

    if (!visited[next]) {
        DFS(next);
    } else if (!finished[next]) {
        for (int i = next; i != v; i = student[i]) {
            cnt++;
        }
        cnt++;
    }
    finished[v] = true;
}


int main() {
    cin >> T;

    while(T--) {
        memset(visited, false, sizeof(visited));
        memset(finished, false, sizeof(finished));
        cin >> N;

        for (int i = 1; i <= N; ++i) {
            cin >> student[i];
        }

        cnt = 0;
        for (int i = 1; i <= N; ++i) {
            if (!visited[i]) {
                DFS(i);
            }
        }
        cout << N - cnt << '\n';
    }
    return 0;
}