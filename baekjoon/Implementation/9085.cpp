// 백준 9085번 : 더하기
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;


    while (T--) {
        int N, sum = 0;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int num;
            cin >> num;
            sum += num;
        }
        cout << sum << '\n';
    }
    return 0;
}