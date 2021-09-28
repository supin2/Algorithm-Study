// 백준 14499번 : 주사위 굴리기
#include <iostream>
#include <vector>

using namespace std;

#define EAST 0
#define WEST 1
#define NORTH 2
#define SOUTH 3

int dice[4][3] =
{{ -1, 0, -1 },
 {  0, 0, 0 },
 { -1, 0, -1 },
 { -1, 0, -1 }};

int map[21][21] = { 0, };
int D[4][2] = {{ 0, 1 }, { 0, -1 }, { -1, 0 }, { 1, 0 }};

void rolling(int dir) {
    int top = dice[1][1];
    
    if (dir == EAST) {
        dice[1][1] = dice[1][0];
        dice[1][0] = dice[3][1];
        dice[3][1] = dice[1][2];
        dice[1][2] = top;
    } else if (dir == WEST) {
        dice[1][1] = dice[1][2];
        dice[1][2] = dice[3][1];
        dice[3][1] = dice[1][0];
        dice[1][0] = top;
    } else if (dir == SOUTH) {
        dice[1][1] = dice[0][1];
        dice[0][1] = dice[3][1];
        dice[3][1] = dice[2][1];
        dice[2][1] = top;
    } else if (dir == NORTH) {
        dice[1][1] = dice[2][1];
        dice[2][1] = dice[3][1];
        dice[3][1] = dice[0][1];
        dice[0][1] = top;
    }
}

int main() {
    int N, M, y, x, K;
    cin >> N >> M >> y >> x >> K;
    
    vector<int> moves;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < K; i++) {
        int m;
        cin >> m;
        moves.push_back(m - 1);
    }
    
    for (int i = 0; i < moves.size(); i++) {
        int move = moves[i];
        int nextY = y + D[move][0];
        int nextX = x + D[move][1];
        
        if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= M) {
            continue;
        }
        rolling(move);
        int top = dice[1][1];
        int bottom = dice[3][1];
        
        cout << top << '\n';
        
        if (map[nextY][nextX] == 0) {
            map[nextY][nextX] = bottom;
        } else {
            dice[3][1] = map[nextY][nextX];
            map[nextY][nextX] = 0;
        }
        y = nextY, x = nextX;
    }
    return 0;
}