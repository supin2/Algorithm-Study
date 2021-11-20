// 백준 15969번 : 행복
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, maxNum = -1, minNum = 1001;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        maxNum = max(maxNum, num);
        minNum = min(minNum, num);
    }
    cout << maxNum - minNum;
    return 0;
}