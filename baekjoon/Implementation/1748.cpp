// 백준 1748번 : 수 이어 쓰기 1
#include <iostream>

using namespace std;

int main() {
    int N, ret = 0;
    cin >> N;

    for (int i = 1; i <= N; i *= 10) {
        ret += N - i + 1;
    }
    cout << ret;
    return 0;
}