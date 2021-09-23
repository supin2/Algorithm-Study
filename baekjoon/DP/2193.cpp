// 백준 2193번 : 이친수
#include <iostream>

using namespace std;

int main() {
    int N;
    long long dp[91][2] = { { 0, 0 }, { 0, 1 }, { 1, 0 } };

    cin >> N;

    for (int i = 3; i <= N; ++i) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];
    }
    
    cout << dp[N][0] + dp[N][1] << '\n';

    return 0;
}