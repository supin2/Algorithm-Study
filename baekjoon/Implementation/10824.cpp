// 백준 10824번 : 네 수
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string A, B, C, D;
    cin >> A >> B >> C >> D;

    long long sum1 = stoll(A + B);
    long long sum2 = stoll(C + D);

    cout << sum1 + sum2;
    return 0;
}