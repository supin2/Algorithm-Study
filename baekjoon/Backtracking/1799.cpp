// 백준 1799번 : 비숍
#include <iostream>
#include <vector>

using namespace std;

int N, ans = -1;
int board[11][11];
bool canPut[11][11] = { false, };
vector<pair<int, int>> v;

int dir[2][2] = {{ 1, 1 }, { -1, -1 }};

bool isValid(int y, int x) {
    int cnt = 1;
    while (cnt < N) {
        for (int i = 0; i < 2; i++) {
            int nextY = y + dir[i][0] * cnt;
            int nextX = x + dir[i][1] * cnt;

            if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= N) {
                continue;
            }
            if (canPut[nextY][nextX]) {
                return false;
            }
        }
        cnt++;
    }
    return true;
}

void dfs(int cnt) {
    for (int i = 0; i < v.size(); i++) {
        int y = v[i].first;
        int x = v[i].second;
        if (canPut[y][x]) {
            continue;
        }

        if (isValid(y, x)) {
            canPut[y][x] = true;
            dfs(cnt + 1);
            canPut[y][x] = false;
        }
    }
    ans = max(ans, cnt);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) {
                v.push_back(make_pair(i, j));
            }
        }
    }
    dfs(0);
    
    cout << ans;
    return 0;
}