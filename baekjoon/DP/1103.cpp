// 백준 1103번 : 게임
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
vector<string> board;
int dp[51][51];
bool visited[51][51];
int D[4][2] = {{ -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 }};

int dfs(int y, int x) {
    if (y < 0 || y >= N || x < 0 || x >= M || board[y][x] == 'H') {
        return 0;
    }
    if (visited[y][x]) {
        cout << -1;
        exit(0);
    }
    int &ret = dp[y][x];
    if (ret != -1) {
        return ret;
    }
    ret = 0;
    visited[y][x] = true;
    
    for (int i = 0; i < 4; i++) {
        int nextY = y + D[i][0] * (board[y][x] - '0');
        int nextX = x + D[i][1] * (board[y][x] - '0');

        ret = max(ret, 1 + dfs(nextY, nextX));
    }
    visited[y][x] = false;
    return ret;
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string str = "";
        cin >> str;
        board.push_back(str);
    }

    memset(dp, -1, sizeof(dp));
    memset(visited, false, sizeof(visited));
    int ans = dfs(0, 0);

    cout << ans;
    return 0;
}