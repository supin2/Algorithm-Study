// 백준 9663번 : N-Queen
#include <iostream>

using namespace std;

int N, ans = 0;
int board[16]; // idx : 행, 값 : 열

bool isPossible(int row) {
    for (int i = 0; i < row; i++) {
        if (board[row] == board[i] || (abs(board[row] - board[i]) ==  row - i )) {
            return false;
        }
    }
    return true;
}

void dfs(int row) {
    if (row == N) {
        ans++;
        return;
    }
    for (int col = 0; col < N; col++) {
        board[row] = col;
        
        if (isPossible(row)) {
            dfs(row + 1);
        }
    }
}

int main() {
    cin >> N;

    dfs(0);
    
    cout << ans;
    return 0;
}