// 백준 2851번 : 슈퍼 마리오
#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int diff = 987654321, sum = 0, ans;

    for (int i = 0, num; i < 10; i++) {
        cin >> num;
        sum += num;
        if (diff > abs(100 - sum)) {
            diff = abs(100 - sum);
            ans = sum;
        } else if (diff == abs(100 - sum)) {
            if (ans < sum) {
                ans = sum;
            }
        }
    }
    cout << ans;
    return 0;
}