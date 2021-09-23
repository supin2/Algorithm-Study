// 백준 11726번 : 2xn 타일링
#include <iostream>

using namespace std;

const int MAX = 1001;
int n;
int dp[MAX];

int main() {
    cin >> n;

    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; ++i) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
    }
    cout << dp[n] << '\n';
    return 0;
}