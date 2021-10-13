// 백준 18111번 : 마인크래프트
#include <iostream>

using namespace std;

int N, M, B;
int arr[501][501];
int minH = 257, maxH = -1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> M >> B;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            maxH = max(maxH, arr[i][j]);
            minH = min(minH, arr[i][j]);
        }
    }
    int ans = 1e8, height = -1;
    for (int k = minH; k <= maxH; k++) {
        int sum = 0, used = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (arr[i][j] < k) { // 블록 놓기
                    sum += (k - arr[i][j]);
                    used -= (k - arr[i][j]);
                } else if (arr[i][j] > k) { // 블록 없애기
                    sum += (arr[i][j] - k) * 2;
                    used += (arr[i][j] - k);
                }
            }
        }
        if (used < 0) {
            if (abs(used) > B) {
                continue;
            } else {
                if (ans >= sum) {
                    ans = sum;
                    height = max(height, k);
                }
            }
        } else {
            if (ans >= sum) {
                ans = sum;
                height = max(height, k);
            }
        }
    }
    cout << ans << ' ' << height;
    return 0;
}
