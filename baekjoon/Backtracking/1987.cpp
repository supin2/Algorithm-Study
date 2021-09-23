// 백준 1987번 : 알파벳
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int MAX = 21;

int R, C, ans;
string board[MAX];
bool alphabet[26];


int dy[4] = { 0,  0, 1, -1 };
int dx[4] = { 1, -1, 0,  0 };

void solution(int y, int x, int cnt) {
    for (int i = 0; i < 4; ++i) {
        int nextY = y + dy[i];
        int nextX = x + dx[i];

        if (nextY < 0 || nextY >= R || nextX < 0 || nextX >= C) continue; // 범위 벗어난 지점
        else {
            if (!alphabet[board[nextY][nextX] - 'A']) { // 밟지 않았던 알파벳
                alphabet[board[nextY][nextX] - 'A'] = true;
                solution(nextY, nextX, cnt + 1);
                alphabet[board[nextY][nextX] - 'A'] = false;
            }
        }
    }
    ans = max(ans, cnt);
}

int main() {
    cin >> R >> C;

    for (int i = 0; i < R; ++i) {
        cin >> board[i];
    }

    alphabet[board[0][0] - 'A'] = true;
    solution(0, 0, 1);
    cout << ans;

    return 0;
}