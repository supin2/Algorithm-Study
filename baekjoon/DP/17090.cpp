// 백준 17090번 : 미로 탈출하기
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
vector<string> maze;
int dp[501][501];

int dfs(int y, int x) {
    if (y < 0 || y >= N || x < 0 || x >= M) {
        return 1;
    }
    int &ret = dp[y][x];
    if (ret != -1) {
        return ret;
    }
    ret = 0;

    switch (maze[y][x]) {
        case 'U' :
            ret = dfs(y - 1, x);
            break;
        case 'R' :
            ret = dfs(y, x + 1);
            break;
        case 'D' :
            ret = dfs(y + 1, x);
            break;
        case 'L' :
            ret = dfs(y, x - 1);
            break;
    }
    return ret;
}

int main() {
    cin >> N >> M;
    
    string str = "";
    for (int i = 0; i < N; i++) {
        cin >> str;
        maze.push_back(str);
    }
    memset(dp, -1, sizeof(dp));

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (dfs(i, j) == 1) {
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}