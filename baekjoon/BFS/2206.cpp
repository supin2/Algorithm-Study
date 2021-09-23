// 백준 2206번 : 벽 부수고 이동하기
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 1001;
int N, M;
int map[MAX][MAX];
int cache[MAX][MAX][2]; // 마지막 인덱스는 벽 부쉈는지 유무 확인 (1 : 부술 수 있는 상태, 0 : 이미 부쉈음)

int dy[4] = { 0,  0, 1, -1 };
int dx[4] = { 1, -1, 0,  0 };

int BFS() {
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(0, 0), 1)); // (0, 0) 부터 시작, 벽 부술 수 있는 상태이니 1로 시작
    cache[0][0][1] = 1;

    while (!q.empty()) {
        int nowY = q.front().first.first;
        int nowX = q.front().first.second;
        int wall = q.front().second;
        q.pop();

        if (nowY == N - 1 && nowX == M - 1) {
            return cache[nowY][nowX][wall];
        }
        for (int i = 0; i < 4; ++i) {
            int nextY = nowY + dy[i];
            int nextX = nowX + dx[i];

            if (0 <= nextY && nextY < N && 0 <= nextX && nextX < M) {
                if (map[nextY][nextX] == 1 && wall == 1) { // 벽을 만나고, 벽을 부술 수 있는 경우
                    cache[nextY][nextX][wall - 1] = cache[nowY][nowX][wall] + 1;
                    q.push(make_pair(make_pair(nextY, nextX), wall - 1));
                } else if (map[nextY][nextX] == 0 && cache[nextY][nextX][wall] == 0) { // 벽이 아니고, 지나지 않은 곳인 경우
                    cache[nextY][nextX][wall] = cache[nowY][nowX][wall] + 1;
                    q.push(make_pair(make_pair(nextY, nextX), wall));
                }
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {

        string temp;

        cin >> temp;

        for (int j = 0; j < M; j++)
            map[i][j] = temp[j] - '0';

    }

    cout << BFS() << '\n';
    return 0;
}