// 백준 1783번 : 병든 나이트
#include <iostream>

using namespace std;

int main() {
    int N, M, ans;
    cin >> N >> M;

    if (N == 1) ans = 1;
    else if (N == 2) ans = min(4, (M + 1)/2);
    else if (N >= 3) {
        if (M <= 6) {
            ans = min(4, M);
        } else {
            ans = M - 2;
        }
    }
    cout << ans << '\n';
    return 0;
}