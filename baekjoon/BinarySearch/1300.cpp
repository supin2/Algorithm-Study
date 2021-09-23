// 백준 1300번 : K번째 수
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N, K, ans = 0;
    cin >> N >> K;

    int first = 1, last = K;
    while (first <= last) {
        int mid = (first + last)/2;
        int cnt = 0;
        for (int i = 1; i <= N; i++) {
            cnt += min(N, mid / i);
        }
        if (cnt >= K) {
            ans = mid;
            last = mid - 1;
        } else {
            first = mid + 1;
        }
    }
    cout << ans << '\n';
    return 0;
}