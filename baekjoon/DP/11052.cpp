// 백준 11052번 : 카드 구매하기
#include <iostream>
#include <cstring>

using namespace std;

int N;
int P[1001];
int dp[1001];

int solution(int cnt) {
    if (cnt >= N + 1) return 0;

    int &ret = dp[cnt];
    if (ret != -1) return ret;

    ret = solution(cnt + 1);
    if (cnt + 1 <= N) {
    }

}


int main() {
    memset(dp, -1, sizeof(dp));
    cin >> N;

    for (int i = 1; i <= N; ++i) {
        cin >> P[i];
    }

    return 0;
}