// 백준 1932번 : 정수 삼각형
#include <iostream>
#include <cstring>

using namespace std;
#define MAX 501
int n;
int triangle[MAX][MAX];
int cache[MAX][MAX];

int solution(int y, int x) {
    int &ret = cache[y][x];
    if (ret != -1) return ret;

    if (y == n - 1) {
        return ret = triangle[y][x];
    }

    return ret = max(solution(y + 1, x), solution(y + 1, x + 1)) + triangle[y][x];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    memset(cache, -1, sizeof(cache));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cin >> triangle[i][j];
        }
    }
    cout << solution(0, 0) << '\n';

    return 0;
}