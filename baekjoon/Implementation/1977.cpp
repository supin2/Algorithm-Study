// 백준 1977번 : 완전제곱수
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int M, N, sum = 0, minNum = 10001;
    cin >> M >> N;

    for (int i = 1; i <= 100; i++) {
        int tmp = i * i;
        if (tmp >= M && tmp <= N) {
            sum += tmp;
            minNum = min(minNum, sum);
        }
    }
    if (sum == 0) {
        cout << -1;
    } else {
        cout << sum << '\n' << minNum;
    }
    return 0;
}