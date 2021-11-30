// 백준 12101번 : 1, 2, 3 더하기 2
#include <bits/stdc++.h>

using namespace std;

int n, k, order;
vector<int> ret;
int arr[3] = { 1, 2, 3 };

void dfs(int sum) {
    if (sum > n) {
        return;
    }
    if (sum == n) {
        order++;
        if (order == k) {
            for (int i = 0; i < ret.size() - 1; i++) {
                cout << ret[i] << '+';
            }
            cout << ret.back();
            exit(0);
        }
        return;
    }
    for (int i = 0; i < 3; i++) {
        ret.push_back(arr[i]);
        dfs(sum + arr[i]);
        ret.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    dfs(0);

    if (order < k || order == 0) {
        cout << -1;
    }
    return 0;
}