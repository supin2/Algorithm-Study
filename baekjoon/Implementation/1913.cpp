// 백준 1913번 : 달팽이
#include <iostream>

using namespace std;

int arr[1000][1000];
int D[4][2] = {{ 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 }}; // 하, 우, 상, 좌

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;

    int dir = 0, y = 0, x = 0;
    int a, b;

    for (int i = N*N; i > 0; i--) {
        arr[y][x] = i;
        if (i == M) {
            a = y + 1;
            b = x + 1;
        }

        if (y + D[dir][0] < 0 || y + D[dir][0] >= N || x + D[dir][1] < 0 || x + D[dir][1] >= N || arr[y + D[dir][0]][x + D[dir][1]] != 0) {
            dir = (dir + 1) % 4;
        }
        y += D[dir][0];
        x += D[dir][1];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << a << ' ' << b;
    return 0;
}