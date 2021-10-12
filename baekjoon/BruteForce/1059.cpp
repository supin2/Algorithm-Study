// 백준 1059번 : 좋은 구간
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int L, arr[51];
    cin >> L;
    for (int i = 0; i < L; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + L);

    int n, low = -1, high = -1;
    cin >> n;
    for (int i = 0; i < L; i++) {
        if (arr[i] == n) {
            cout << 0;
            return 0;
        }
        if (arr[i] > n && high == -1) {
            high = arr[i] - 1;
            if (i == 0) {
                low = 1;
            } else {
                low = arr[i - 1] + 1;
            }
        }
    }
    cout << (n - low) * (high - n + 1) + (high - n);
    return 0;
}