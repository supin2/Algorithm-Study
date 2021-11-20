// 백준 15964번 : 이상한 기호
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long A, B;
    cin >> A >> B;

    cout << (A + B) * (A - B);
    return 0;
}