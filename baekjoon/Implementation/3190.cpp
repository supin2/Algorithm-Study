// 백준 3190번 : 뱀
#include <iostream>
#include <deque>
#include <queue>

using namespace std;

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

int board[101][101] = { 0, };

int D[4][2] = {{ -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 }};

int changeDir(int now, char dir) {
    if (dir == 'L') {
        if (now == UP) {
            return LEFT;
        } else if (now == RIGHT) {
            return UP;
        } else if (now == DOWN) {
            return RIGHT;
        } else if (now == LEFT) {
            return DOWN;
        }
    } else if (dir == 'D') {
        if (now == UP) {
            return RIGHT;
        } else if (now == RIGHT) {
            return DOWN;
        } else if (now == DOWN) {
            return LEFT;
        } else if (now == LEFT) {
            return UP;
        }
    }
    return -1;
}

int main() {
    int N, K, L;
    deque<pair<int, int>> dq;
    queue<pair<int, char>> q;
    
    cin >> N >> K;
    
    while (K--) {
        int i, j;
        cin >> i >> j;
        board[i][j] = 1; // 사과가 있는 곳
    }
    
    cin >> L;
    
    while (L--) {
        int t;
        char d;
        cin >> t >> d;
        q.push(make_pair(t, d));
    }
    
    // 처음 시작 세팅
    dq.push_back({ 1, 1 });
    board[1][1] = 2;
    int dir = RIGHT;
    int time = 0;
    
    while (true) {
        time++;
        int nextY = dq[0].first + D[dir][0];
        int nextX = dq[0].second + D[dir][1];
        
        if (nextY < 1 || nextY > N || nextX < 1 || nextX > N || board[nextY][nextX] == 2) {
            break;
        }
        
        if (board[nextY][nextX] == 1) { // 사과일 경우
            board[nextY][nextX] = 2;
            dq.push_front(make_pair(nextY, nextX));
        } else {
            board[nextY][nextX] = 2;
            dq.push_front(make_pair(nextY, nextX));
            board[dq.back().first][dq.back().second] = 0;
            dq.pop_back();
        }
        
        if (!q.empty()) {
            int turnTime = q.front().first;
            char turn = q.front().second;
            
            if (time == turnTime) {
                dir = changeDir(dir, turn);
                q.pop();
            }
        }
    }
    cout << time;
    return 0;
}