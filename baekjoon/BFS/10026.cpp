// 백준 10026번 : 적록색약
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 100;
int N;
string grid[MAX];
string grid2[MAX];
bool visited[MAX][MAX];

int dy[4] = { 0,  0, -1, 1 };
int dx[4] = { 1, -1,  0, 0 };

void BFS(int y, int x, char color) {
    queue<pair<int, int>> q;
    visited[y][x] = true;
    q.push(make_pair(y, x));

    while(!q.empty()) {
        int nowY = q.front().first;
        int nowX = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nextY = nowY + dy[i];
            int nextX = nowX + dx[i];

            if (0 <= nextY && nextY < N && 0 <= nextX && nextX < N) {
                if (grid[nextY][nextX] == color && !visited[nextY][nextX]) {
                    visited[nextY][nextX] = true;
                    q.push(make_pair(nextY, nextX));
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> grid[i];
    }
    vector<int> V;
    for (int k = 0; k < 2; ++k) {
        int cnt = 0;
        memset(visited, false, sizeof(visited));

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (!visited[i][j]) {
                    cnt++;
                    BFS(i, j, grid[i][j]);
                }
            }
        }
        V.push_back(cnt);

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == 'G') {
                    grid[i][j] = 'R';
                }
            }
        }
    }

    for (int i = 0; i < V.size(); ++i) {
        cout << V[i] << " ";
    }
    return 0;
}