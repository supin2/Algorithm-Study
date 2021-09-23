// 백준 2580번 : 스도쿠
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int board[9][9];
vector<pair<int, int>> pos;
int zero_cnt = 0;

bool canFill(pair<int, int> point) {
    for (int i = 0; i < 9; i++) {
        if (board[point.first][i] == board[point.first][point.second] && i != point.second) {
            return false;
        }
        if (board[i][point.second] == board[point.first][point.second] && i != point.first) {
            return false;
        }
    }
    int row_scope = point.first / 3;
    int col_scope = point.second / 3;

    for (int i = row_scope * 3; i < row_scope * 3 + 3; i++) {
        for (int j = col_scope * 3; j < col_scope * 3 + 3; j++) {
            if (board[i][j] == board[point.first][point.second] && i != point.first && j != point.second) {
                return false;
            }
        }
    }
    return true;
}

bool make_sudoku(int N) {
    if (N == zero_cnt) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << board[i][j] << ' ';
            }
            cout << '\n';
        }
        return true;
    }
    for (int num = 1; num <= 9; num++) {
        board[pos[N].first][pos[N].second] = num;
        if (canFill(pos[N])) {
            if (make_sudoku(N + 1)) {
                return true;
            }
        }
    }
    board[pos[N].first][pos[N].second] = 0;
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> board[i][j];
            if (board[i][j] == 0) {
                pos.push_back(make_pair(i, j));
                zero_cnt++;
            }
        }
    }
    make_sudoku(0);

    return 0;
}