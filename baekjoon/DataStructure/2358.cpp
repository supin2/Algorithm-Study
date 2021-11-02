// 백준 2358번 : 평행선
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, ans = 0;
    map<int, int> mx, my;
    cin >> n;

    for (int i = 0, x, y; i < n; i++) {
        cin >> x >> y;
        mx[x]++;
        my[y]++;
    }

    for (auto it = mx.begin(); it != mx.end(); it++) {
        if (it->second >= 2) {
            ans++;
        }
    }
    for (auto it = my.begin(); it != my.end(); it++) {
        if (it->second >= 2) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}