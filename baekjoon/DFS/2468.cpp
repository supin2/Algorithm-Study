#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 100 + 1;
int N;
int area[MAX][MAX];
bool visited[MAX][MAX];
int low_level = 101;
int max_level = 0;

int dy[4] = {  0, 0, -1, 1 };
int dx[4] = { -1, 1,  0, 0 };

void DFS(int y, int x, int level) {
    for (int i = 0; i < 4; ++i) {
        int nextY = y + dy[i];
        int nextX = x + dx[i];

        if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= N) continue;
        if (area[nextY][nextX] <= level || visited[nextY][nextX]) continue;
        visited[y][x] = true;
        DFS(nextY, nextX, level);
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int ans = 1;
    memset(area, 0, sizeof(area));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> area[i][j];
            low_level = min(area[i][j], low_level);
            max_level = max(area[i][j], max_level);
        }
    }
    cout << low_level << " " << max_level <<'\n';
    for (int i = low_level; i < max_level; ++i) {
        int cnt = 0;
        memset(visited, false, sizeof(visited));
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                if (area[j][k] > i && !visited[j][k]) {
                    visited[j][k] = true;
                    cnt++;
                    // cout << cnt << ". (" << j << ", " << k << ")" << '\n';
                    DFS(j, k, i);
                }
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans << '\n';
    return 0;
}