// 백준 14888번 : 연산자 끼워넣기
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> opnd, optr;
int maxNum = -1000000000, minNum = 1000000000;

void dfs(int sum, int idx) {
    if (idx == N) {
        maxNum = max(maxNum, sum);
        minNum = min(minNum, sum);
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (optr[i] > 0) {
            optr[i]--;

            if (i == 0) {
                dfs(sum + opnd[idx], idx + 1);
            } else if (i == 1) {
                dfs(sum - opnd[idx], idx + 1);
            } else if (i == 2) {
                dfs(sum * opnd[idx], idx + 1);
            } else {
                dfs(sum / opnd[idx], idx + 1);
            }
            optr[i]++;
        }
    }
}

int main() {
    cin >> N;

    opnd.resize(N);
    optr.resize(4);
    for (int i = 0; i < N; i++) {
        cin >> opnd[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> optr[i];
    }

    dfs(opnd[0], 1);

    cout << maxNum << '\n' << minNum;
    return 0;
}