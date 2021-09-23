// 백준 11053번 : 가장 긴 증가하는 부분 수열
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 1000 + 1;
int N;
int numbers[MAX], dp[MAX];

int solution(int num) { // Top-down (각 숫자에서 시작해서 순열 길이 얻기)
    int &ret = dp[num];
    if (ret != -1) return ret;

    ret = 1;

    for (int i = num + 1; i <= N; ++i) {
        if (numbers[num] < numbers[i]) {
            ret = max(ret, solution(i) + 1);
        }
    }
    return ret;
}


int main() {
    memset(dp, -1, sizeof(dp));
    cin >> N;

    for (int i = 1; i <= N; ++i) {
        cin >> numbers[i];
    }

    int ret = 0;
    for (int i = 1; i <= N; ++i) {
        ret = max(ret, solution(i));
    }
    cout << ret << '\n';
    return 0;
}