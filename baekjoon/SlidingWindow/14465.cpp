// 백준 14465번 : 소가 길을 건너간 이유 5
#include <iostream>

using namespace std;

int N, K, B, ans = 987654321;
int arr[100001];

int main() {
    cin >> N >> K >> B;

    for (int i = 0, num; i < B; i++) {
        cin >> num;
        arr[num] = 1;
    }

    int light = 0, broken = 0;
    for (int i = 1; i <= K; i++) {
        if (arr[i] == 1) {
            broken++;
        }
    }
    ans = broken;
    for (int i = K + 1; i <= N; i++) {
        if (arr[i - K] == 1) {
            broken--;
        }
        if (arr[i] == 1) {
            broken++;
        }
        ans = min(ans, broken);
    }
    cout << ans;
    return 0;
}