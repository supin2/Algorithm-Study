// 백준 4158번 : CD
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while (true) {
        int N, M, num, ans = 0;

        cin >> N >> M;
        vector<int> v1(N), v2(M);

        if (N == 0 && M == 0) {
            break;
        }

        for (int i = 0; i < N; i++) {
            cin >> v1[i];
        }
        for (int i = 0; i < M; i++) {
            cin >> v2[i];
        }

        int it1 = 0, it2 = 0;
        while (true) {
            if (it1 >= N || it2 >= M) {
                break;
            }

            if (v1[it1] == v2[it2]) {
                ans++;
                it1++;
                it2++;
            } else if (v1[it1] < v2[it2]) {
                it1++;
            } else if (v1[it1] > v2[it2]) {
                it2++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}