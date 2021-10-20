// 백준 2304번 : 창고 다각형
#include <iostream>

using namespace std;

int arr[1001], leftMax[1001], rightMax[1001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, ans = 0;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        arr[a] = b;
    }

    leftMax[0] = arr[0];
    for (int i = 1; i <= 1000; i++) {
        leftMax[i] = max(leftMax[i - 1], arr[i]);
    }
    rightMax[1000] = arr[1000];
    for (int i = 999; i >= 0; i--) {
        rightMax[i] = max(rightMax[i + 1], arr[i]);
    }

    for (int i = 0; i <= 1000; i++) {
        ans += min(leftMax[i], rightMax[i]);
    }
    cout << ans;
    return 0;
}