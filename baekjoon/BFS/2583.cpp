// 백준 2583번 : 영역 구하기
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 101;
int M, N, K;
int matrix[MAX][MAX];
bool visited[MAX][MAX];
vector<int> V;

int dy[4] = { 0,  0, 1, -1 };
int dx[4] = { 1, -1, 0,  0 };

int BFS(int y, int x) {
    queue<pair<int, int>> q;
    visited[y][x] = true;
    q.push(make_pair(y, x));
    
    int cnt = 1;

    while(!q.empty()) {
        int nowY = q.front().first;
        int nowX = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nextY = nowY + dy[i];
            int nextX = nowX + dx[i];

            if (0 <= nextY && nextY < M && 0 <= nextX && nextX < N) {
                if (matrix[nextY][nextX] == 0 && !visited[nextY][nextX]) {
                    visited[nextY][nextX] = true;
                    cnt++;
                    q.push(make_pair(nextY, nextX));
                }
            }
        }
    }
    return cnt;
}


int main() {
    cin >> M >> N >> K;
    memset(matrix, 0, sizeof(matrix));
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < K; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int j = y1; j < y2; ++j) {
            for (int l = x1; l < x2; ++l) {
                matrix[j][l] = 1;
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (matrix[i][j] == 0 && !visited[i][j]) {
                cnt++;
                V.push_back(BFS(i, j));
            }
        }
    }
    sort(V.begin(), V.end());
    cout << cnt << '\n';

    for (int i = 0; i < V.size(); ++i) {
        cout << V[i] << " ";
    }

    return 0;

}