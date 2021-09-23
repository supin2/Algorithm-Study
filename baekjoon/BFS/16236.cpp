// 백준 16236번 : 아기 상어
#include <iostream>
#include <queue>

using namespace std;

const int MAX = 21;
int N;
int area[MAX][MAX];
bool visited[MAX][MAX];
pair<int, int> start;

int dy[4] = { 0,  0, -1, 1 };
int dx[4] = { 1, -1,  0, 0 };

typedef struct {
    int dist;
    int y;
    int x;
} fish;

bool operator< (fish f1, fish f2) {
    if (f1.dist == f2.dist) {
        if (f1.y == f2.y) {
            return f1.x > f2.x;
        }
        return f1.y > f2.y;
    }
    return f1.dist > f2.dist;
}

void BFS() {
    queue<fish> q;
    q.push({ 0, start.first, start.second });
    visited[start.first][start.second] = true;

    int size = 2; // 최초 사이즈 : 2
    int eaten = 0; // 먹은 물고기
    int time = 0; // 엄마 상어에게 도움 요청하는 시간

    while (1) { // 먹을 물고기가 없을 때까지
        priority_queue<fish> pq;

        while(!q.empty()) {
            int dist = q.front().dist;
            int nowY = q.front().y;
            int nowX = q.front().x;
            q.pop();

            for (int i = 0; i < 4; ++i) { // 상, 하, 좌, 우 탐색
                int nextY = nowY + dy[i];
                int nextX = nowX + dx[i];

                if (nextY < 0 && nextY >= N && nextX < 0 && nextX >= N) continue;
                if (area[nextY][nextX] > size || visited[nextY][nextX]) continue;

                visited[nextY][nextX] = true;
                q.push({ dist + 1, nextY, nextX });

                if (area[nextY][nextX] < size && area[nextY][nextX] != 0) { // 먹을 수 있는 물고기들 저장
                    pq.push({ dist + 1, nextY, nextX });
                }
                
            }
        }

        if (!pq.empty()) { // 먹을 수 있는 물고기가 존재하면
            auto prey = pq.top(); // 먹을 수 있는 물고기(조건에 제일 부합하는 물고기)
            pq.pop();
            area[prey.y][prey.x] = 0;
            eaten++;
            time = prey.dist;
            q.push({ prey.dist, prey.y, prey.x });
            visited[prey.y][prey.x] = true;
        } else { // 먹을 수 있는 물고기가 존재하지 않으면
            cout << time << '\n';
            break;
        }

        if (eaten == size) {
            size++;
            eaten = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> area[i][j];
            if (area[i][j] == 9) {
                start = make_pair(i, j);
                area[i][j] = 0;
            }
        }
    }
    BFS();
    return 0;
}