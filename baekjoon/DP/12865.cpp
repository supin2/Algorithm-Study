// 백준 12865번 : 평범한 배낭
#include <iostream>
#include <cstring>

using namespace std;

int N, K;
pair<int, int> knapsack[101];
int dp[100001][101];

int solution(int capacity, int item) {
    if (item == N + 1) return 0;

    int &ret = dp[capacity][item];
    if (ret != -1) return ret;

    ret = solution(capacity, item + 1);
    if (capacity >= knapsack[item].first) {
        ret = max(ret, knapsack[item].second + solution(capacity - knapsack[item].first, item + 1));
    }
    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp));
    cin >> N >> K;

    for (int i = 1; i <= N; ++i) {
        cin >> knapsack[i].first >> knapsack[i].second;
    }

    cout << solution(K, 1) << '\n';

    return 0;
}