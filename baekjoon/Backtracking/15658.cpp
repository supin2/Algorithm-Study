// 백준 15658번 : 연산자 끼워넣기 (2)
#include <iostream>

using namespace std;

#define PLUS 0
#define MINUS 1
#define MULTIPLY 2
#define DIVIDE 3

int N;
int arr[101];
int optr[4] = { 0, };
int maxNum = -1000000000, minNum = 1000000000;

void dfs(int idx, int sum) {
    if (idx == N) {
        maxNum = max(maxNum, sum);
        minNum = min(minNum, sum);
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (optr[i] <= 0) {
            continue;
        }
        optr[i]--;
        if (i == PLUS) {
            dfs(idx + 1, sum + arr[idx]);
        } else if (i == MINUS) {
            dfs(idx + 1, sum - arr[idx]);
        } else if (i == MULTIPLY) {
            dfs(idx + 1, sum * arr[idx]);
        } else if (i == DIVIDE) {
            dfs(idx + 1, sum / arr[idx]);
        }
        optr[i]++;
    }
}


int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> optr[i];
    }
    dfs(1, arr[0]);

    cout << maxNum << '\n' << minNum;
    return 0;
}