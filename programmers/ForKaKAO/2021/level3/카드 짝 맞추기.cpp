#include <string>
#include <vector>
#include <queue>

using namespace std;

#define INF 987654321

struct Point {
    int row, col, cnt;    
};

vector<vector<int>> Board;

int D[4][2] = {{ -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 }};

int bfs(Point src, Point dst) {
    bool visited[4][4] = { false };
    queue<Point> q;
    q.push(src);
    
    while (!q.empty()) {
        Point curr = q.front();
        q.pop();
        
        if (curr.row == dst.row && curr.col == dst.col) {
            return curr.cnt;
        }
        for (int i = 0; i < 4; i++) {
            int nr = curr.row + D[i][0];
            int nc = curr.col + D[i][1];
            
            if (nr < 0 || nr > 3 || nc < 0 || nc > 3) {
                continue;
            }
            if (!visited[nr][nc]) {
                visited[nr][nc] = true;
                q.push({ nr, nc, curr.cnt + 1 });
            }
            for (int j = 0; j < 2; j++) {
                if (Board[nr][nc] != 0) {
                    break;
                }
                if (nr + D[i][0] < 0 || nr + D[i][0] > 3 || nc + D[i][1] < 0 || nc + D[i][1] > 3) {
                    break;
                }
                nr += D[i][0];
                nc += D[i][1];
            }
            if (!visited[nr][nc]) {
                visited[nr][nc] = true;
                q.push({ nr, nc, curr.cnt + 1 });
            }
        }
    }
    return INF;
}

int permutate(Point src) {
    int ret = INF;
    for (int num = 1; num <= 6; num++) {
        vector<Point> card;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (Board[i][j] == num) {
                    card.push_back({ i, j, 0 });
                }
            }
        }
        
        if (card.empty()) continue;
        
        int one = bfs(src, card[0]) + bfs(card[0], card[1]) + 2;
        int two = bfs(src, card[1]) + bfs(card[1], card[0]) + 2;
        
        for (int i = 0; i < 2; i++) {
            Board[card[i].row][card[i].col] = 0;
        }
        ret = min(ret, one + permutate(card[1]));
        ret = min(ret, two + permutate(card[0]));
        
        for (int i = 0; i < 2; i++) {
            Board[card[i].row][card[i].col] = num;
        }
    }
    if (ret == INF) {
        return 0;
    }
    return ret;
}

int solution(vector<vector<int>> board, int r, int c) {
    Board = board;
    return permutate({ r, c, 0 });
}