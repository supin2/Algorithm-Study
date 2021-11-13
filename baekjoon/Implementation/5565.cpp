// 백준 5565번 : 영수증
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int sum = 0;
    cin >> sum;
    for (int i = 0, num; i < 9; i++) {
        cin >> num;
        sum -= num;
    }
    cout << sum;
    return 0;
}