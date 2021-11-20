// 백준 1453번 : 피시방 알바
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, ans = 0;
    cin >> N;
    vector<int> v;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        if (find(v.begin(), v.end(), num) == v.end()) {
            v.push_back(num);
        } else {
            ans++;
        }
    }
    cout << ans;
    return 0;
}