#include <string>
#include <vector>
#include <cstring>

using namespace std;

int M, N;
vector<string> cBoard;

bool visited[31][31];
int dir[3][2] = {{ 1, 0 }, { 1, 1 }, { 0, 1 }};

bool square_check(int y, int x, char ch) {
    bool flag = true;
    for (int n = 0; n < 3; n++) {
        if (cBoard[y + dir[n][0]][x + dir[n][1]] != ch) {
            flag = false;
            break;
        }
    }
    if (flag) {
        visited[y][x] = true;
        for (int n = 0; n < 3; n++) {
            visited[y + dir[n][0]][x + dir[n][1]] = true;
        }
    }
    return flag;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    M = m, N = n, cBoard = board;
    bool erase = false;

    do {
        erase = false;
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (cBoard[i][j] != '0') {
                    if (square_check(i, j, cBoard[i][j])) {
                        erase = true;
                    }
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == true) {
                    cBoard[i][j] = '0';
                    answer++;
                }
            }
        }
        int y, x;
        for (int i = 0; i < n; i++) {
            for (int j = m - 1; j >= 0; j--) {
                if (cBoard[j][i] == '0') {
                    y = j, x = i;
                    bool change = false;
                    while (true) {
                        y--;
                        if (y < 0) {
                            break;
                        }
                        if (cBoard[y][x] != '0') {
                            change = true;
                            break;
                        }
                    }
                    if (change == true) {
                        cBoard[j][i] = cBoard[y][x];
                        cBoard[y][x] = '0';
                    }
                }
            }
        }
    } while (erase);
    return answer;
}