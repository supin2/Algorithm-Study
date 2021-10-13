// 백준 10211번 : Maximum Subarray
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    
    while (T--) {
        int N, arr[1001];
        cin >> N;

        int sum = 0, ans = -1e8;
        for (int i = 0, num; i < N; i++) {
            cin >> num;
            sum = max(0, sum) + num;
            ans = max(ans, sum);
        }
        cout << ans << '\n';
    }
    return 0;
}