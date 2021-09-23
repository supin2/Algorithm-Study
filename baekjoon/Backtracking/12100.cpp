// 백준 12100번 : 2048 (Easy)
#include <iostream>

using namespace std;

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

int N;
int Board[21][21];
int maxNum = -1;

void combine(int move) {
    if (move == UP) {
        bool check[21][21] = { false };
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int tmp = j;
                while (true) {
                    if (tmp <= 0 || Board[tmp - 1][i] != 0) {
                        break;
                    }
                    Board[tmp - 1][i] = Board[tmp][i];
                    Board[tmp][i] = 0;
                    tmp--;
                }
                if (tmp > 0 && Board[tmp - 1][i] == Board[tmp][i] && !check[tmp - 1][i]) {
                    check[tmp - 1][i] = true;
                    Board[tmp - 1][i] *= 2;
                    Board[tmp][i] = 0;
                }
            }
        }
    } else if (move == RIGHT) {
        bool check[21][21] = { false };
        for (int i = 0; i < N; i++) {
            for (int j = N - 1; j >= 0; j--) {
                int tmp = j;
                while (true) {
                    if (tmp >= N - 1 || Board[i][tmp + 1] != 0) {
                        break;
                    }
                    Board[i][tmp + 1] = Board[i][tmp];
                    Board[i][tmp] = 0;
                    tmp++;
                }
                if (tmp < N - 1 && Board[i][tmp + 1] == Board[i][tmp] && !check[i][tmp + 1]) {
                    check[i][tmp + 1] = true;
                    Board[i][tmp + 1] *= 2;
                    Board[i][tmp] = 0;
                }
            }
        }
    } else if (move == DOWN) {
        bool check[21][21] = { false };
        for (int i = 0; i < N; i++) {
            for (int j = N - 1; j >= 0; j--) {
                int tmp = j;
                while (true) {
                    if (tmp >= N - 1 || Board[tmp + 1][i] != 0) {
                        break;
                    }
                    Board[tmp + 1][i] = Board[tmp][i];
                    Board[tmp][i] = 0;
                    tmp++;
                }
                if (tmp < N - 1 && Board[tmp + 1][i] == Board[tmp][i] && !check[tmp + 1][i]) {
                    check[tmp + 1][i] = true;
                    Board[tmp + 1][i] *= 2;
                    Board[tmp][i] = 0;
                }
            }
        }
    } else if (move == LEFT) {
        bool check[21][21] = { false };
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int tmp = j;
                while (true) {
                    if (tmp <= 0 || Board[i][tmp - 1] != 0) {
                        break;
                    }
                    Board[i][tmp - 1] = Board[i][tmp];
                    Board[i][tmp] = 0;
                    tmp--;
                }

                if (tmp > 0 && Board[i][tmp - 1] == Board[i][tmp] && !check[i][tmp - 1]) {
                    check[i][tmp - 1] = true;
                    Board[i][tmp - 1] *= 2;
                    Board[i][tmp] = 0;
                }
            }
        }
    }
}

void play_2048(int cnt) {
    if (cnt == 5) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                maxNum = max(maxNum, Board[i][j]);
            }
        }
        return;
    }

    int cBoard[21][21];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cBoard[i][j] = Board[i][j];
        }
    }

    for (int move = 0; move < 4; move++) {
        combine(move);
        play_2048(cnt + 1);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                Board[i][j] = cBoard[i][j];
            }
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> Board[i][j];
        }
    }
    play_2048(0);

    cout << maxNum;
    return 0;
}