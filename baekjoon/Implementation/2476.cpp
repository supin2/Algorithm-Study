// 백준 2476번 : 주사위 게임
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    int maxSum = 0;
    for (int i = 0; i < N; i++) {
        int arr[6] = { 0, };
        int sum = 0;
        for (int j = 0, num; j < 3; j++) {
            cin >> num;
            arr[num - 1]++;
        }
        int maxNum = -1;
        for (int i = 0; i < 6; i++) {
            if (arr[i] == 3) {
                sum = (i + 1) * 1000 + 10000;
                break;
            } else if (arr[i] == 2) {
                sum = (i + 1) * 100 + 1000;
                maxNum = -1;
                break;
            } else if (arr[i] == 1) {
                maxNum = i + 1;
            }
        }
        if (maxNum != -1) {
            sum = maxNum * 100;
        }
        maxSum = max(sum, maxSum);
    }
    cout << maxSum;
    return 0;
}