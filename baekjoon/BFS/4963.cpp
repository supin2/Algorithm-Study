// 백준 4963번 : 섬의 개수
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 50 + 1;
int W, H;
int square[MAX][MAX];
bool visited[MAX][MAX];

int dy[8] = { 0,  0, 1, -1, 1,  1, -1, -1 };
int dx[8] = { 1, -1, 0,  0, 1, -1, -1,  1 };

void BFS(int y, int x) {
    queue<pair<int,int>> q;
    visited[y][x] = true;
    q.push(make_pair(y, x));

    while(!q.empty()) {
        int nowY = q.front().first;
        int nowX = q.front().second;
        q.pop();

        for (int i = 0; i < 8; ++i) {
            int nextY = nowY + dy[i];
            int nextX = nowX + dx[i];

            if (0 <= nextY && nextY < H && 0 <= nextX && nextX < W) {
                if (!visited[nextY][nextX] && square[nextY][nextX] == 1) {
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

    while(1) {
        cin >> W >> H;
        if (W == 0 && H == 0) break;

        memset(square, 0, sizeof(square));
        memset(visited, false, sizeof(visited));

        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                cin >> square[i][j];
            }
        }
        
        int cnt = 0;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (!visited[i][j] && square[i][j] == 1) {
                    cnt++;
                    BFS(i, j);
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}