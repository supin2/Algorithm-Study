// 백준 2231번 : 분해합

#include <iostream>
#include <algorithm>

using namespace std;

int N, ans = 0;

void input() {
    cin >> N;
}

void solution() {
    for (int i = 1; i < N; ++i) {
        int num = i;
        int temp = i;

        while (temp) {
            num += (temp % 10);
            temp /= 10;
        }
        if (num == N) {
            ans = i;
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    solution();

    cout << (ans == 0 ? 0 : ans) << '\n';

    return 0;
}