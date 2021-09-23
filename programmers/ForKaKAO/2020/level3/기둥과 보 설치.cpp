#include <string>
#include <vector>

using namespace std;

int Pillar[101][101] = { 0, };
int Bar[101][101] = { 0, };

bool canBuildPillar(int x, int y) {
    if (y == 0 || Pillar[x][y - 1] == 1) {
        return true;
    }
    if ((x > 0 && Bar[x - 1][y] == 1) || Bar[x][y] == 1) {
        return true;
    }
    return false;
}

bool canBuildBar(int x, int y) {
    if (Pillar[x][y - 1] == 1 || Pillar[x + 1][y - 1] == 1) {
        return true;
    }
    if (x > 0 && Bar[x - 1][y] == 1 && Bar[x + 1][y] == 1) {
        return true;
    }
    return false;
}

bool canDelete(int x, int y) {
    for (int i = max(0, x - 1); i <= x + 1; i++) {
        for (int j = y; j <= y + 1; j++) {
            if (Pillar[i][j] == 1 && canBuildPillar(i, j) == false) {
                return false;
            }
            if (Bar[i][j] == 1 && canBuildBar(i, j) == false) {
                return false;
            }
        }
    }
    return true;
}


vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    
    for (auto build : build_frame) {
        int x = build[0], y = build[1], a = build[2], b = build[3];
        if (b == 1) { // 설치
            if (a == 0) { // 기둥
                if (canBuildPillar(x, y)) {
                    Pillar[x][y] = 1;
                }
            } else { // 보
                if (canBuildBar(x, y)) {
                    Bar[x][y] = 1;
                }
            }
        } else { // 삭제
            if (a == 0) { // 기둥
                Pillar[x][y] = 0;
                if (!canDelete(x, y)) {
                    Pillar[x][y] = 1;
                }
            } else { // 보
                Bar[x][y] = 0;
                if (!canDelete(x, y)) {
                    Bar[x][y] = 1;
                }
            }
        }
    }
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (Pillar[i][j] == 1) {
                answer.push_back({ i, j, 0 });
            }
            if (Bar[i][j] == 1) {
                answer.push_back({ i, j, 1 });
            }
        }
    }
    return answer;
}