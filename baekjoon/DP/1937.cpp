// 백준 1937번 : 욕심쟁이 판다
#include <iostream>
#include <cstring>

using namespace std;

int n;
int bamboo[501][501];
int dp[501][501];
int d[4][2] = {{ -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 }};

int dfs(int y, int x) {
    int &ret = dp[y][x];
    if (ret != -1) {
        return ret;
    }
    ret = 1;
    for (int i = 0; i < 4; i++) {
        int nextY = y + d[i][0];
        int nextX = x + d[i][1];
        
        if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n) {
            continue;
        }
        if (bamboo[y][x] < bamboo[nextY][nextX]) {
            ret = max(ret, dfs(nextY, nextX) + 1);
        }
    }
    return ret;
}

int main() {
    cin >> n;
    int ans = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> bamboo[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans = max(ans, dfs(i, j));
        }
    }
    cout << ans;
    return 0;
}