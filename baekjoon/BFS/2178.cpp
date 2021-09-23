// 백준 2178번 : 미로탐색
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 100;

int N, M;
int maze[MAX][MAX];
int cache[MAX][MAX];
bool visited[MAX][MAX];

int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };


void BFS() {
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    cache[0][0] = 1;
    visited[0][0] = true;

    while(!q.empty()) {
        int nowY = q.front().first;
        int nowX = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nextY = nowY + dy[i];
            int nextX = nowX + dx[i];

            if (0 <= nextY && nextY < N && 0 <= nextX && nextX < M) {
                if (maze[nextY][nextX] == 1 && !visited[nextY][nextX]) {
                    q.push(make_pair(nextY, nextX));
                    cache[nextY][nextX] = cache[nowY][nowX] + 1;
                    visited[nextY][nextX] = true;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    memset(cache, 0, sizeof(cache));
    memset(visited, false, sizeof(visited));

	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < M; j++)	{
            maze[i][j] = temp[j] - '0';
        }
	}

    BFS();
    cout << cache[N - 1][M - 1] << '\n';
    return 0;
}