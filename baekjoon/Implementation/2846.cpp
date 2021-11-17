// 백준 2846번 : 오르막길
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, arr[1001];
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    int maxSize = 0, nowSize = 0;
    int before = arr[0];
    for (int i = 1; i < N; i++) {
        if (before < arr[i]) {
            nowSize += (arr[i] - before);
        } else {
            maxSize = max(maxSize, nowSize);
            nowSize = 0;
        }
        before = arr[i];
    }
    maxSize = max(maxSize, nowSize);
    cout << maxSize;
    return 0;
}