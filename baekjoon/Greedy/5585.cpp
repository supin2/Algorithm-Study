// 백준 5585번 : 거스름돈
#include <iostream>

using namespace std;

int main() {
    int money, ans = 0;
    int arr[6] = { 500, 100, 50, 10, 5, 1 };

    cin >> money;
    money = 1000 - money;

    for (int i = 0; i < 6; i++) {
        ans += money / arr[i];
        money = money % arr[i];
    }

    cout << ans << '\n';
    return 0;
}