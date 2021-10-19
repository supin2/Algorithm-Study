// 백준 13300번 : 방 배정
#include <iostream>
#include <cstring>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, K, arr[2][7];
    int ans = 0;
    memset(arr, 0, sizeof(arr));
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        arr[a][b]++;
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 1; j <= 6; j++) {
            int cnt = arr[i][j];
            if (cnt % K == 0) {
                ans += (cnt / K);
            } else {
                ans += (cnt / K) + 1;
            }
        }
    }
    cout << ans;
    return 0;
}