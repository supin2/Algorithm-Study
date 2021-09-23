// 백준 11403번 : 경로 찾기
#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 100 + 1;
int N;
int arr[MAX][MAX];
bool visited[MAX];

void DFS(int num) {
    for (int i = 0; i < N; ++i) {
        if (arr[num][i] == 1 && !visited[i]) {
            visited[i] = true;
            DFS(i);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < N; ++i) {
        memset(visited, false, sizeof(visited));
        if (!visited[i]) {
            DFS(i);
        }
        for (int j = 0; j < N; ++j) {
            if (visited[j]) {
                arr[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}