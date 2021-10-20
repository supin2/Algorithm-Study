// 백준 14719번 : 빗물
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int H, W, ans = 0;
    cin >> H >> W;

    vector<int> block(W, 0), left(W, 0), right(W, 0);

    for (int i = 0; i < W; i++) {
        cin >> block[i];
    }

    left[0] = block[0];
    for (int i = 1; i < W; i++) {
        left[i] = max(left[i - 1], block[i]);
    }

    right[W - 1] = block[W - 1];
    for (int i = W - 2; i >= 0; i--) {
        right[i] = max(right[i + 1], block[i]);
    }

    for (int i = 0; i < W; i++) {
        ans += min(left[i], right[i]) - block[i];
    }
    cout << ans;
    return 0;
}