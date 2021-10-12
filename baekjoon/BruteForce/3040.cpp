// 백준 3040번 : 백설 공주와 일곱 난쟁이
#include <iostream>

using namespace std;

int arr[9], ret[7];
bool visited[9];

void dfs(int idx, int cnt, int sum) {
    if (cnt == 7) {
        if (sum == 100) {
            for (int i = 0; i < 7; i++) {
                cout << ret[i] << '\n';
            }
            exit(0);
        }
        return;
    }
    for (int i = idx; i < 9; i++) {
        if (visited[i]) {
            continue;
        }
        visited[i] = true;
        sum += arr[i];
        ret[cnt] = arr[i];
        dfs(i, cnt + 1, sum);
        sum -= arr[i];
        visited[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for (int i = 0; i < 9; i++) {
        cin >> arr[i];
    }
    dfs(0, 0, 0);
    
    return 0;
}