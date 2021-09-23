// 백준 5427번 : 불
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 1000;
int N, W, H;
string building[MAX];
bool visited[MAX][MAX];

vector<pair<int, int>> fire_pos;
pair<int, int> saram_pos;

int dy[4] = { 0,  0, 1, -1 };
int dx[4] = { 1, -1, 0,  0 };

int BFS(int y, int x) {
    queue<pair<int, int>> q1;
    queue<pair<int, int>> q2;
    q1.push(make_pair(y, x));

    for (int i = 0; i < fire_pos.size(); ++i) {
        q2.push(fire_pos[i]);
    }

    int ans = 0;

    while(!q1.empty()) {
        int fireSize = q2.size();
        for (int i = 0; i < fireSize; ++i) { // 불 먼저 퍼트리기
            int fire_y = q2.front().first;
            int fire_x = q2.front().second;
            q2.pop();

            for (int j = 0; j < 4; ++j) {
                int nextY = fire_y + dy[j];
                int nextX = fire_x + dx[j];

                if (0 <= nextY && nextY < H && 0 <= nextX && nextX < W) {
                    if (building[nextY][nextX] == '.') {
                        building[nextY][nextX] = '*';
                        q2.push(make_pair(nextY, nextX));
                    }
                }
            }
        }

        int saramCnt = q1.size();
        for (int i = 0; i < saramCnt; ++i) { // 불 퍼진 다음 사람 이동시키기
            int nowY = q1.front().first;
            int nowX = q1.front().second;
            q1.pop();

            if (nowY == 0 || nowY == H - 1 || nowX == 0 || nowX == W - 1) { // 가장 자리에 있으면 다음 턴에 무조건 탈출
                return ans + 1;
            }

            for (int j = 0; j < 4; ++j) {
                int nextY = nowY + dy[j];
                int nextX = nowX + dx[j];

                if (0 <= nextY && nextY < H && 0 <= nextX && nextX < W) {
                    if (building[nextY][nextX] != '*' && building[nextY][nextX] != '#' && !visited[nextY][nextX]) {
                        visited[nextY][nextX] = true;
                        q1.push(make_pair(nextY, nextX));
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

    cin >> N;

    while (N--) {
        cin >> W >> H;
        memset(visited, false, sizeof(visited));
        fire_pos.clear();

        for (int i = 0; i < H; ++i) {
            cin >> building[i];

            for (int j = 0; j < W; ++j) {
                if (building[i][j] == '*') {
                    fire_pos.push_back(make_pair(i, j)); // 최초 불 위치 저장
                } else if (building[i][j] == '@') {
                    saram_pos = make_pair(i, j); // 최초 사람 위치 저장
                }
            }
        }
        int ret = BFS(saram_pos.first, saram_pos.second);
        if (ret == -1) {
            cout << "IMPOSSIBLE" << '\n';
        } else {
            cout << ret << '\n';
        }
    }
    return 0;
}