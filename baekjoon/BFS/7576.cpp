// 백준 7576번 : 토마토
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

#define MAX 1001
int M, N, ans = 0;
int box[MAX][MAX];
queue<pair<int,int>> ripen;

int dy[4] = { 0,  0, 1, -1 };
int dx[4] = { 1, -1, 0,  0 };

void input() {
    scanf("%d %d", &M, &N);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            scanf("%d", &box[i][j]);
            if (box[i][j] == 1) {
                ripen.push(make_pair(i, j));
            }
        }
    }
}

void BFS() {
    while (!ripen.empty()) {
        int y = ripen.front().first;
        int x = ripen.front().second;
        
        ripen.pop();

        for (int i = 0; i < 4; ++i) {
            int nextY = y + dy[i];
            int nextX = x + dx[i];

            if (0 <= nextY && nextY < N && 0 <= nextX && nextX < M && box[nextY][nextX] == 0) {
                box[nextY][nextX] = box[y][x] + 1;
                ripen.push(make_pair(nextY, nextX));
            }
        }
    }
}

int main() {
    input();
    BFS();

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (box[i][j] == 0) {
                printf("-1\n");
                return 0;
            }
            if (box[i][j] > ans) {
                ans = box[i][j];
            }
        }
    }
    printf("%d\n", ans - 1);

    return 0;
}