// 백준 2576번 : 홀수
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int minNum = 101, sum = 0;
    for (int i = 0, num; i < 7; i++) {
        cin >> num;
        if (num % 2 == 1) {
            sum += num;
            if (minNum > num) {
                minNum = num;
            }
        }
    }
    if (minNum == 101) {
        cout << -1;
    } else {
        cout << sum << '\n' << minNum;
    }
    return 0;
}