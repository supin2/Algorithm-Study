// 백준 17626번 : Four Squares
#include <iostream>
#include <cstring>

using namespace std;

int N;
int dp[50001];

int dfs(int num) {
    int &ret = dp[num];
    if (ret != -1) {
        return ret;
    }
    
    ret = num;
    for (int i = 0; i*i <= num; i++) {
        ret = min(ret, dfs(num - i*i) + 1);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    memset(dp, -1, sizeof(dp));
    dp[0] = 0, dp[1] = 1;
    
    cin >> N;
    cout << dfs(N);
    return 0;
}

// #include <iostream>
// #include <cstring>

// using namespace std;

// int N;
// int dp[50001];

// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
    
//     memset(dp, -1, sizeof(dp));
//     dp[0] = 0, dp[1] = 1;
    
//     cin >> N;
    
//     for (int i = 2; i <= N; i++) {
//         int temp = 1e8;
//         for (int j = 1; j * j <= i; j++) {
//             temp = min(temp, dp[i - j*j] + 1);
//         }
//         dp[i] = temp;
//     }
//     cout << dp[N];
//     return 0;
// }
