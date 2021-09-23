#include <string>
#include <vector>
#include <queue>

using namespace std;

struct car {
    int y, x, dir;
};

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

int solution(vector<vector<int>> board) {
    int answer = 987654321;
    int N = board.size();
    int cache[25][25][4];
    int D[4][2] = {{ -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 }}; // UP, RIGHT, DOWN, LEFT
    
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 25; j++) {
            for (int k = 0; k < 4; k++) {
                cache[i][j][k] = 987654321;
            }
        }
    }
    
    queue<car> q;
    q.push({ 0, 0, 2 });
    q.push({ 0, 0, 3 });
    
    for (int i = 0; i < 4; i++) {
        cache[0][0][i] = 0;
    }
    
    while (!q.empty()) {
        int nowY = q.front().y;
        int nowX = q.front().x;
        int nowDir = q.front().dir;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nextY = nowY + D[i][0];
            int nextX = nowX + D[i][1];
            
            if (nextY < 0 || nextY > N - 1 || nextX < 0 || nextX > N - 1) {
                continue;
            }
            if (board[nextY][nextX] == 1) {
                continue;
            }
            
            if (nextY == N - 1 && nextX == N - 1) {
                if (nowDir == i) {
                    answer = min(answer, cache[nowY][nowX][nowDir] + 100);
                } else {
                    answer = min(answer, cache[nowY][nowX][nowDir] + 600);
                }
                continue;
            }
            
            int nextCost = cache[nowY][nowX][nowDir] + 100;
            if (nowDir == UP || nowDir == DOWN) {
                if (i == LEFT || i == RIGHT) {
                    nextCost += 500;
                }
            } else if (nowDir == LEFT || nowDir == RIGHT) {
                if (i == UP || i == DOWN) {
                    nextCost += 500;
                }
            }
            
            if (cache[nextY][nextX][i] > nextCost) {
                cache[nextY][nextX][i] = nextCost;
                q.push({ nextY, nextX, i });
            }
            // if (nowDir == i || (nowDir + 2) % 4 == i) {
            //     if (cache[nextY][nextX][i] > cache[nowY][nowX][nowDir] + 100) {
            //         cache[nextY][nextX][i] = cache[nowY][nowX][nowDir] + 100;
            //         q.push({ nextY, nextX, i });
            //     }
            // } else if (nowDir != i) {
            //     if (cache[nextY][nextX][i] > cache[nowY][nowX][nowDir] + 600) {
            //         cache[nextY][nextX][i] = cache[nowY][nowX][nowDir] + 600;
            //         q.push({ nextY, nextX, i });
            //     }
            // }
        }
    }
    
    // for (int i = 0; i < 4; i++) {
    //     answer = min(answer, cache[N - 1][N - 1][i]);
    // }
    
    return answer;
}