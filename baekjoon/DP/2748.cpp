// 백준 2748번 : 피보나치 수 2
#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 90 + 1;
int n;
long long dp[MAX];

long long solution(int num) { // Top-down
    if (num == 0) return 0;
    if (num == 1) return 1;

    long long &ret = dp[num];
    if (ret != -1) return ret;

    return ret = solution(num - 1) + solution(num - 2);
}

int main() {
    memset(dp, -1, sizeof(dp));
    cin >> n;

    cout << solution(n) << '\n';
    return 0;
}