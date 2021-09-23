// 백준 2759번 : 계단 오르기
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
int stairs[301];
int cache[301];

int solution(int num) {
    if (num == 0) return 0;

    int &ret = cache[num];
    if (ret != -1) return ret;

    ret = max(stairs[num] + stairs[num - 1] + solution(num - 3), stairs[num] + solution(num - 2));
    return ret;
}

int main() {
    cin >> N;
    memset(cache, -1, sizeof(cache));

    for (int i = 1; i <= N; ++i) {
        cin >> stairs[i];
    }
    cout << solution(N) << '\n';
    return 0;
}