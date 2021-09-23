// 백준 1018번 : 체스판 다시 칠하기
#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

#define MAX 51

int N, M, ans = INT_MAX;
char board[MAX][MAX];

string WB[8] = {
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"
};

string BB[8] = {
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB"
};


void input() {
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> board[i][j];
        }
    }
}

int check_WB(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board[x + i][y + j] != WB[i][j]) cnt++;
        }
    }
    return cnt;
}
int check_BB(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board[x + i][y + j] != BB[i][j]) cnt++;
        }
    }
    return cnt;
}

void solution() {
    for (int i = 0; i + 7 < N; ++i) {
        for (int j = 0; j + 7 < M; ++j) {
            int tmp = min(check_WB(i, j), check_BB(i, j));
            ans = min(ans, tmp);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    solution();

    cout << ans;

    return 0;
}