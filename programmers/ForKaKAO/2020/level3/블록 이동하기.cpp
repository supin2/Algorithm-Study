#include <string>
#include <vector>
#include <queue>

using namespace std;

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

struct Point {
    int row, col, dir, time;
};

int D[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } }; // 상, 하, 좌, 우
int Drot[2][4][2] = { {{ 1, 1 }, { 1, -1 }, { -1, -1 }, { -1, 1 }},
                      {{ 1, -1 }, { -1, -1 }, { -1, 1 }, { 1, 1 }} }; // 시계/반시계, 방향성(회전하는 블록 기준), 행/열
int Dcor[2][4][2] = { {{ -1, 1 }, { 1, 1 }, { 1, -1 }, { -1, -1 }},
                      {{ -1, -1 }, { -1, 1 }, { 1, 1 }, { 1, -1 }} }; // 회전하는 위치에 1이 있는지 유무 확인(회전축 기준)

vector<vector<int>> Board;
int N;
queue<pair<Point, Point>> q;
bool visited[100][100][4] = { 0, };

bool isValid(Point pt[2]) {
    for (int i = 0; i < 2; i++) {
        if (pt[i].row < 0 || pt[i].row > N - 1 || pt[i].col < 0 || pt[i].col > N - 1) { // 범위를 벗어나거나
            return false; 
        } 
        if (Board[pt[i].row][pt[i].col] == 1) { // 이동한 자리가 1이거나
            return false;
        }
        if (visited[pt[i].row][pt[i].col][pt[i].dir]) { // 이미 방문한 곳이면
            return false;
        }
    }
    return true;
}

int rotate(Point curr[2], int ccw, int idx) { // 현재 위치정보, 시계(0)/반시계(1)방향, 회전축
    Point newPt[2];
    int a = idx, b = (idx + 1) % 2; // a를 회전축으로 함
    int dir = curr[a].dir; // 회전축의 방향성 저장
    newPt[0] = { curr[a].row, curr[a].col, 
                (curr[a].dir + (ccw == 1 ? 3 : 1)) % 4, curr[a].time + 1 };
    newPt[1] = { curr[b].row + Drot[ccw][dir][0], curr[b].col + Drot[ccw][dir][1],
                (curr[b].dir + (ccw == 1 ? 3 : 1)) % 4, curr[b].time + 1 };
    
    if (isValid(newPt) == false) {
        return 0;
    }
    if (Board[curr[a].row + Dcor[ccw][dir][0]][curr[a].col + Dcor[ccw][dir][1]] == 1) {
        return 0;
    } 
    
    for (int i = 0; i < 2; i++) {
        if (newPt[i].row == N - 1 && newPt[i].col == N - 1) {
            return newPt[i].time;
        }
        visited[newPt[i].row][newPt[i].col][newPt[i].dir] = true;
    }
    q.push(make_pair(newPt[0], newPt[1]));
    return 0;
}


int solution(vector<vector<int>> board) {
    Board = board;
    N = board.size();
    
    q.push(make_pair(Point{ 0, 0, RIGHT, 0 }, Point{ 0, 1, LEFT, 0 }));
    visited[0][0][RIGHT] = true;
    visited[0][1][LEFT] = true;
    
    while (!q.empty()) {
        Point curr[2], newPt[2];
        curr[0] = q.front().first;
        curr[1] = q.front().second;
        q.pop();
        
        for (int j = 0; j < 4; j++) { // 상하좌우로 이동시켜봄
            for (int i = 0; i < 2; i++) {
                newPt[i] = { curr[i].row + D[j][0], curr[i].col + D[j][1], curr[i].dir, curr[i].time + 1 }; // 다음 좌표정보
            }
            
            if (isValid(newPt) == false) { // 이동할 수 없는 경우
                continue;
            }
            
            for (int i = 0; i < 2; i++) {
                if (newPt[i].row == N - 1 && newPt[i].col == N - 1) { // 도달한 경우
                    return newPt[i].time;
                }
                visited[newPt[i].row][newPt[i].col][newPt[i].dir] = true;
            }
            q.push(make_pair(newPt[0], newPt[1]));
        }
        
        // 회전시켜봄
        for (int ccw = 0; ccw < 2; ccw++) { // 0 : 시계방향, 1 : 반시계방향
            for (int i = 0; i < 2; i++) { // 회전축 정하기
                int ret = rotate(curr, ccw, i);
                if (ret) {
                    return ret;
                }
            }
        }
    }
    return 0;
}