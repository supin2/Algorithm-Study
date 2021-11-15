// 백준 2566번 : 최댓값
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int maxNum = -1, y, x, num;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> num;
            if (maxNum < num) {
                maxNum = num;
                y = i + 1;
                x = j + 1;
            }
        }
    }
    cout << maxNum << '\n' << y << ' ' << x;
    return 0;
}