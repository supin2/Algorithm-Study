// 백준 18428번 : 감시 피하기
#include <bits/stdc++.h>

using namespace std;

int N;
char arr[7][7];
vector<pair<int, int>> v;
int D[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

bool isValid() {
    for (auto pos : v) {
        for (int i = 0; i < 4; i++) {
            int y = pos.first;
            int x = pos.second;
            while (y >= 0 && y < N && x >= 0 && x < N) {
                if (arr[y][x] == 'S') {
                    return false;
                }
                if (arr[y][x] == 'O') {
                    break;
                }
                y += D[i][0];
                x += D[i][1];
            }
        }
    }
    return true;
}

void dfs(int cnt) {
    if (cnt == 3) {
        if (isValid()) {
            cout << "YES";
            exit(0);
        }
        return;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == 'X') {
                arr[i][j] = 'O';
                dfs(cnt + 1);
                arr[i][j] = 'X';
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'T') {
                v.push_back(make_pair(i, j));
            } 
        }
    }
    dfs(0);
    cout << "NO";
    return 0;
}