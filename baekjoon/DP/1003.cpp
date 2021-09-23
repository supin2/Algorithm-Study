// 백준 1003번 : 피보나치 함수
#include <iostream>

using namespace std;

int T;
int dp[41] = { 0, 1, };

int fib(int n) {
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main() {
    cin >> T;

    for (int i = 0; i < T; ++i) {
        int N;
        cin >> N;
        
        if (N == 0) {
            cout << 1 << " " << 0 << '\n';
        } else if (N == 1) {
            cout << 0 << " " << 1 << '\n';
        } else {
            cout << fib(N - 1) << " " << fib(N) << '\n';
        }
    }
    return 0;
}