// 백준 2357번 : 최솟값과 최댓값
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;
    vector<int> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        auto minMax = minmax_element(v.begin() + a - 1, v.begin() + b);

        cout << *minMax.first << ' ' << *minMax.second << '\n';
    }
    return 0;
}