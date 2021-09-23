#include <string>
#include <vector>

using namespace std;

vector<vector<int>> Board;
int N;

bool canFill(int x, int y) {
    for (int i = 0; i < x; i++) {
        if (Board[i][y] != 0) {
            return false;
        }
    }
    return true;
}



bool check(int x, int y, int row, int col) {
    int zero = 0, last = -1;
    for (int a = x; a < x + row; a++) {
        for (int b = y; b < y + col; b++) {
            if (Board[a][b] == 0) {
                if (!canFill(a, b)) {
                    return false;
                }
                zero++;
                if (zero > 2) {
                    return false;
                }
            } else {
                if (last != -1 && Board[a][b] != last) {
                    return false;
                }
                last = Board[a][b];
            }
        }
    }
    for (int a = x; a < x + row; a++) {
        for (int b = y; b < y + col; b++) {
            Board[a][b] = 0;
        }
    }
    return true;
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    Board = board;
    N = board.size();
    int cnt;
    
    do { // 한 번 순회해서 지워진 블록때문에 또 다시 지워질 수 있는 블록이 생길 수 있으므로
        cnt = 0;
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < N; y++) {
                if (x < N - 2 && y < N - 1 && check(x, y, 3, 2)) {
                    cnt++;
                } else if (x < N - 1 && y < N - 2 && check(x, y, 2, 3)) {
                    cnt++;
                }
            }
        }
        answer += cnt;
    } while (cnt); // 지울 수 있는 블록이 있으면 반복
    return answer;
}