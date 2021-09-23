// 백준 14889번 : 스타트와 링크
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int arr[21][21];
bool visited[21] = { false, };
int diff = 987654321;

void dfs(int cnt, int num) {
    if (cnt == N/2) {
        vector<int> start, link;
        int sScore = 0, lScore = 0;
        for (int i = 1; i <= N; i++) {
            if (visited[i]) {
                start.push_back(i);
            } else {
                link.push_back(i);
            }
        }

        for (int i = 0; i < N/2; i++) {
            for (int j = 0; j < N/2; j++) {
                sScore += arr[start[i] - 1][start[j] - 1];
                lScore += arr[link[i] - 1][link[j] - 1];
            }
        }
        diff = min(diff, abs(sScore - lScore));
        return;
    }

    for (int i = num; i <= N; i++) {
        if (visited[i]) {
            continue;
        }
        visited[i] = true;
        dfs(cnt + 1, i);
        visited[i] = false;
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
    dfs(0, 1);

    cout << diff;
    return 0;
}