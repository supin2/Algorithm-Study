// 백준 1937번 : 욕심쟁이 판다
#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 500 + 1;
int n;
int bamboo[MAX][MAX];
int cache[MAX][MAX];

int dy[4] = {  0, 0, -1, 1 };
int dx[4] = { -1, 1,  0, 0 };


int DFS(int y, int x) {
    int &ret = cache[y][x];
    if (ret != -1) return ret;

    ret = 1;

    for (int i = 0; i < 4; ++i) {
        int nextY = y + dy[i];
        int nextX = x + dx[i];

        if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n) continue;
        if (bamboo[nextY][nextX] <= bamboo[y][x]) continue;
        ret = max(ret, DFS(nextY, nextX) + 1);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int ret = 0;
    memset(bamboo, 0, sizeof(bamboo));
    memset(cache, -1, sizeof(cache));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> bamboo[i][j];
        }
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int temp = DFS(i, j);
            ret = max(ret, temp);
        }
    }

    cout << ret << '\n';

    return 0;
}