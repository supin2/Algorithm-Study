// 백준 9625번 : BABBA
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int K;
    cin >> K;

    int A = 0, B = 1;

    for (int i = 1; i < K; i++) {
        int tmp = A;
        A = B;
        B += tmp;
    }

    cout << A << ' ' << B;
    return 0;
}