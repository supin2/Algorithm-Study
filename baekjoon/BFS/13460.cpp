// 백준 13460번 : 구슬 탈출 2
#include <iostream>
#include <queue>

using namespace std;

const int MAX = 11;

int N, M;
string board[MAX];
pair<int, int> dest;
pair<int, int> red;
pair<int, int> blue;
bool visited[MAX][MAX];

int dy[4] = {  0, 0, -1, 1 };
int dx[4] = { -1, 1,  0, 0 };

int BFS() {
    queue<pair<int, int>> redq;
    queue<pair<int, int>> blueq;

    redq.push(red);
    blueq.push(blue);

    int cnt = 0;

    while(!redq.empty()) {
        int ry = redq.front().first;
        int rx = redq.front().second;
        int by = blueq.front().first;
        int bx = blueq.front().second;

        redq.pop();
        blueq.pop();

        if (ry == dest.first && rx == dest.second) {
            return cnt;
        } else if (by == dest.first && bx == dest.second) {
            return -1;
        }

        for (int i = 0; i < 4; ++i) {
            int next_ry = ry + dy[i];
            int next_rx = rx + dx[i];
            int next_by = by + dy[i];
            int next_bx = bx + dx[i];

            if (next_ry < 0 || next_ry >= N || next_rx < 0 || next_rx >= M) continue;
            if (next_by < 0 || next_by >= N || next_bx < 0 || next_bx >= M) continue;

            if (board[next_ry][next_rx] == '#') continue;
            else if (board[next_ry][next_rx] == '.') {
                redq.push(make_pair(next_ry, next_rx));

                if (board[next_by][next_bx] == '#') {
                    blueq.push(make_pair(by, bx));
                } else {
                    blueq.push(make_pair(next_by, next_bx));
                }
            }
        }
        cnt++;
    }
    return -1;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        cin >> board[i];

        for (int j = 0; j < M; ++j) {
            if (board[i][j] == 'O') dest = make_pair(i, j);
            if (board[i][j] == 'R') red = make_pair(i, j);
            if (board[i][j] == 'B') blue = make_pair(i, j);
        }
    }
    int ret = BFS();

    cout << ret << '\n';

    return 0;
}