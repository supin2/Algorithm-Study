// 백준 2615번 : 오목
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int ans;
int board[21][21];

bool check_row(int y, int x, int stone) { // →
    for (int i = 1; i <= 4; i++) {
        if (board[y][x + i] != stone) {
            return false;
        }
    }
    
    if (board[y][x - 1] == stone || board[y][x + 5] == stone) {
        return false;
    } else {
        return true;
    }
}

bool check_col(int y, int x, int stone) { // ↓
    for (int i = 1; i <= 4; i++) {
        if (board[y + i][x] != stone) {
            return false;
        }
    }
    
    if (board[y - 1][x] == stone || board[y + 5][x] == stone) {
        return false;
    } else {
        return true;
    }
}

bool check_rDig(int y, int x, int stone) { // ↘
    for (int i = 1; i <= 4; i++) {
        if (board[y + i][x + i] != stone) {
            return false;
        }
    }
    
    if (board[y - 1][x - 1] == stone || board[y + 5][x + 5] == stone) {
        return false;
    } else {
        return true;
    }
}

bool check_lDig(int y, int x, int stone) { // ↗
    for (int i = 1; i <= 4; i++) {
        if (board[y - i][x + i] != stone) {
            return false;
        }
    }
    
    if (board[y + 1][x - 1] == stone || board[y - 5][x + 5] == stone) {
        return false;
    } else {
        return true;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(board, 0, sizeof(board));
    
    for (int i = 1; i < 20; i++) {
        for (int j = 1; j < 20; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    
    for (int i = 1; i < 20; i++) {
        for (int j = 1; j < 20; j++) {
            if (board[i][j] == 0) {
                continue;
            }
            if (check_row(i, j, board[i][j])) {
                cout << board[i][j] << '\n' << i << ' ' << j;
                return 0;
            } else if (check_col(i, j, board[i][j])) {
                cout << board[i][j] << '\n' << i << ' ' << j;
                return 0;
            } else if (check_rDig(i, j, board[i][j])) {
                cout << board[i][j] << '\n' << i << ' ' << j;
                return 0;
            } else if (check_lDig(i, j, board[i][j])) {
                cout << board[i][j] << '\n' << i << ' ' << j;
                return 0;
            }
        }
    }
    cout << 0;
    return 0;
}