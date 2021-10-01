// 백준 1520번 : 내리막 길
#include <iostream>
#include <cstring>

using namespace std;

int M, N;
int arr[501][501];
int dp[501][501] = { -1, };

int D[4][2] = {{ -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 }};

int dfs(int y, int x) {
    if (y == M - 1 && x == N - 1) {
        return 1;
    }
    int &ret = dp[y][x];
    if (ret != -1) {
        return ret;
    }
    
    ret = 0;
    for (int i = 0; i < 4; i++) {
        int nextY = y + D[i][0];
        int nextX = x + D[i][1];
        
        if (nextY < 0 || nextY >= M || nextX < 0 || nextX >= N) {
            continue;
        }
        if (arr[nextY][nextX] < arr[y][x]) {
            ret += dfs(nextY, nextX);
        }
    }
    return ret;
}

int main()
{
    cin >> M >> N;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << dfs(0, 0);
    return 0;
}
