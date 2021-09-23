// 백준 3055번 : 탈출
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

const int MAX = 50;
int R, C;
string forest[MAX];
bool visited[MAX][MAX];

pair<int, int> destination;
pair<int, int> start;
queue<pair<int, int>> mole;
queue<pair<int, int>> water;

int dy[4] = { 0,  0, 1, -1 };
int dx[4] = { 1, -1, 0,  0 };

int BFS() {
    mole.push(start);
    visited[start.first][start.second] = true;

    int ans = 0;
    
    while(!mole.empty()) {
        int waterSize = water.size();
        for (int i = 0; i < waterSize; ++i) {
            int nowY = water.front().first;
            int nowX = water.front().second;
            water.pop();

            for (int j = 0; j < 4; ++j) {
                int nextY = nowY + dy[j];
                int nextX = nowX + dx[j];

                if (0 <= nextY && nextY < R && 0 <= nextX && nextX < C) {
                    if (forest[nextY][nextX] == '.') {
                        forest[nextY][nextX] = '*';
                        water.push(make_pair(nextY, nextX));
                    }
                }
            }
        }

        int moleSize = mole.size();
        for (int i = 0; i < moleSize; ++i) {
            int nowY = mole.front().first;
            int nowX = mole.front().second;
            mole.pop();

            if (nowY == destination.first && nowX == destination.second) {
                return ans;
            }

            for (int j = 0; j < 4; ++j) {
                int nextY = nowY + dy[j];
                int nextX = nowX + dx[j];

                if (0 <= nextY && nextY < R && 0 <= nextX && nextX < C) {
                    if (forest[nextY][nextX] != '*' && forest[nextY][nextX] != 'X' && !visited[nextY][nextX]) {
                        visited[nextY][nextX] = true;
                        mole.push(make_pair(nextY, nextX));
                    }
                }
            }
        }
        ans++;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C;

    for (int i = 0; i < R; ++i) {
        cin >> forest[i];

        for (int j = 0; j < C; ++j) {
            if (forest[i][j] == '*')
                water.push(make_pair(i, j));
            else if (forest[i][j] == 'S') 
                start = make_pair(i, j);
            else if (forest[i][j] == 'D') 
                destination = make_pair(i, j);
        }
    }
    memset(visited, false, sizeof(visited));
    int ret = BFS();

    if (ret == -1) {
        cout << "KAKTUS" << '\n';
    } else {
        cout << ret << '\n';
    }

    return 0;
}